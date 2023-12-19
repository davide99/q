import wave


def read_and_print_wav(input_file, output_file):
    with wave.open(input_file, 'rb') as wav_file:
        assert wav_file.getnchannels() == 1
        assert wav_file.getsampwidth() == 2  # bytes
        assert wav_file.getframerate() == 44100

        with open(output_file, 'w') as output:
            for _ in range(wav_file.getnframes()):
                frame = wav_file.readframes(1)
                sample = int.from_bytes(frame, byteorder='little', signed=False)

                output.write(f"{sample}\n")


if __name__ == '__main__':
    # Esempio di utilizzo
    input_wav_file = 'low-e.wav'
    output_txt_file = 'samples.csv'
    read_and_print_wav(input_wav_file, output_txt_file)
