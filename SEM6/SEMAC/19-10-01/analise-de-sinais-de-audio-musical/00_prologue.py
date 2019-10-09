# To add a new cell, type '#%%'
# To add a new markdown cell, type '#%% [markdown]'
#%%
%matplotlib inline
import matplotlib.pyplot as plt
import numpy as np


#%%
# Sinusoid signal in time
fs = 1000
t = np.linspace(0, 1, fs+1)
f = 50 # Hz
x = np.cos(2*np.pi*f*t)

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(t, x)
plt.xlabel('t (s)')
plt.ylabel('x(t)')
plt.show()

#%%
X = np.abs (np.fft.fft(x))
f = np.linspace(0, fs, len(X))

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(f, X)
plt.xlabel('f (Hz)')
plt.ylabel('|X(f)|')
plt.show()

#%%
X = 20 * np.log10 (np.abs (np.fft.fft(x)))
f = np.linspace(0, fs, len(X))

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(f, X)
plt.xlabel('f (Hz)')
plt.ylabel('$|X(f)|_{dB}$')
plt.show()

#%%
X = 20 * np.log10 (np.abs (np.fft.fft(x, len(x)*10)))
f = np.linspace(0, fs, len(X))

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(f, X)
plt.xlabel('f (Hz)')
plt.ylabel('$|X(f)|_{dB}$')
plt.show()

#%%
X = 20 * np.log10 (np.abs (np.fft.fft(x, len(x)*10)))
f = np.linspace(0, fs, len(X))

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(f[900:1100], X[900:1100])
plt.xlabel('f (Hz)')
plt.ylabel('$|X(f)|_{dB}$')
plt.show()

#%%
X = 20 * np.log10 (np.abs (np.fft.fft(x * np.hamming(len(x)), len(x)*10)))
f = np.linspace(0, fs, len(X))

plt.figure()
plt.figure(figsize=(10,5))
plt.grid(color='gray', linestyle=':', linewidth=1)
plt.plot(f[900:1100], X[900:1100])
plt.xlabel('f (Hz)')
plt.ylabel('$|X(f)|_{dB}$')
plt.show()

#%%


