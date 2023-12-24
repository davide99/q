#include <q/pitch/pitch_detector.hpp>
#include <q/utility/float_convert.hpp>
#include <iostream>
#include <fstream>
#include <vector>

namespace q = cycfi::q;

constexpr auto samples_file = "../data/samples.csv";

std::vector<float> read_file() {
    std::ifstream in(samples_file);
    assert(in.is_open());

    std::string line;
    std::vector<float> samples;
    while (std::getline(in, line)) {
        samples.push_back(q::to_float<std::uint16_t, 65535>(std::stoi(line)));
    }

    in.close();
    return samples;
}

int main() {
    constexpr auto sps = 44100;
    constexpr auto lowest_freq = 60.0f;
    constexpr auto highest_freq = 500.0f;

    q::pitch_detector pd(lowest_freq, highest_freq, sps, -45.0f);

    std::vector<float> x = read_file();

    for (auto sample: x) {
        bool is_ready = pd(sample);

        if (is_ready) {
            auto frequency = pd.get_frequency();
            if (frequency != 0.0f)
                std::cout << "Frequency: " << frequency << " Hz" << std::endl;
        }
    }

    return 0;
}
