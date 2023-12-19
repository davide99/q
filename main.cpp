#include <q/support/literals.hpp>
#include <q/pitch/pitch_detector.hpp>
#include <iostream>
#include <fstream>
#include <vector>

namespace q = cycfi::q;
using namespace q::literals;

constexpr auto samples_file = "C:/Users/dav.pisano/Desktop/Q/data/samples.csv";

std::vector<float> read_file() {
    std::ifstream in(samples_file);
    assert(in.is_open());

    std::string line;
    std::vector<float> samples;
    while (std::getline(in, line)) {
        samples.push_back((static_cast<float>(std::stoi(line)) / 65535.0f) * 2.0f - 1.0f);
    }

    in.close();
    return samples;
}

int main() {
    constexpr auto sps = 44100;
    constexpr auto lowest_freq = 60.0_Hz;
    constexpr auto highest_freq = 500.0_Hz;

    q::pitch_detector pd(lowest_freq, highest_freq, sps, -45_dB);

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
