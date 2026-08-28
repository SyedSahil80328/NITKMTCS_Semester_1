import whisper
model = whisper.load_model("turbo")

result = model.transcribe("sample.mp4")
for segment in result["segments"]:
    print(f"[{segment['start']:.2f} --> {segment['end']:.2f}] {segment['text']}")