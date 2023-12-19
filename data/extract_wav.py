import wave


def read_and_print_wav(input_files, output_file):
    with open(output_file, 'w') as output:
        for input_file in input_files:
            with wave.open(input_file, 'rb') as wav_file:
                assert wav_file.getnchannels() == 1
                assert wav_file.getsampwidth() == 2  # bytes
                assert wav_file.getframerate() == 44100

                for _ in range(wav_file.getnframes()):
                    frame = wav_file.readframes(1)
                    sample = int.from_bytes(frame, byteorder='little', signed=False)

                    output.write(f"{sample}\n")


if __name__ == '__main__':
    # Esempio di utilizzo
    input_wav_files = ['low-e.wav', 'a.wav']
    output_txt_file = 'samples.csv'
    read_and_print_wav(input_wav_files, output_txt_file)
