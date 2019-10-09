# To add a new cell, type '#%%'
# To add a new markdown cell, type '#%% [markdown]'
#%%
from IPython import get_ipython

#%%
get_ipython().run_line_magic('matplotlib', 'inline')
import matplotlib.pyplot as plt
import numpy as np
import librosa
import librosa.display


#%%
from os import listdir
from os.path import isfile, join
audiodir = 'audio/'
filenames = [f for f in listdir(audiodir) if isfile(join(audiodir, f))]
print(filenames)


#%%
fname = filenames[6]
y, sr = librosa.load(audiodir + fname)


#%%
plt.figure(figsize=(14, 5))
t = np.linspace(0, len(y)/sr, len(y))
plt.plot(t, y)
plt.xlabel('Time (s)')
plt.show()


#%%
tmin = 0.02
tmax = 0.03
plt.figure(figsize=(14, 5))
plt.plot(t, y)
plt.xlabel('Time (s)')
plt.xlim(tmin, tmax)
plt.show()


#%%
D = librosa.amplitude_to_db(np.abs(librosa.stft(y, n_fft=1024, hop_length=128, win_length=512)), ref=np.max)
plt.figure(figsize=(14, 5))
librosa.display.specshow(D, y_axis='log', x_axis='time')
plt.colorbar(format='%+2.0f dB')
plt.title('Spectrogram')
plt.show()


#%%



#%%



