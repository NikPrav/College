# import the needed libraries
import pyaudio
import wave
import numpy as np
#from matplotlib import pyplot as plt
import random
import soundfile as sf
from python_speech_features import mfcc

fel = "stop"
fle = fel + "/"+fel
CHUNK = 1024 
FORMAT = pyaudio.paInt16 #paInt8
CHANNELS = 1
RATE = 8000 #sample rate
RECORD_SECONDS = 2
#k=1
for j in range(1,81):
	WAVE_OUTPUT_FILENAME = fle+str(j)+".wav"
	p = pyaudio.PyAudio()
	stream = p.open(format=FORMAT,channels=CHANNELS,rate=RATE,input=True,frames_per_buffer=CHUNK) #buffer
	print("* recording")
	frames = []
	for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
		data = stream.read(CHUNK)
		frames.append(data) # 2 bytes(16 bits) per channel
	print("* done recording")
	stream.stop_stream()
	stream.close()
	p.terminate()
	wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
	wf.setnchannels(CHANNELS)
	wf.setsampwidth(p.get_sample_size(FORMAT))
	wf.setframerate(RATE)
	wf.writeframes(b''.join(frames))
	wf.close()
	
	print(j)
	input()
