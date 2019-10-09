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

from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score


#%%
from os import listdir
from os.path import isfile, join
audiodir = 'audio/'
filenames = [f for f in listdir(audiodir) if isfile(join(audiodir, f))]
print(filenames)


#%%
feature_set =[]

for i in range(len(filenames)):
  y, sr = librosa.load(audiodir+filenames[i])
  S = np.abs(librosa.stft(y))
  centroid = librosa.feature.spectral_centroid(S=S)
  centroid_mean = np.mean(centroid)
  centroid_std = np.std(centroid)
  
  flatness = librosa.feature.spectral_flatness(S=S)
  flatness_mean = np.mean(flatness)
  flatness_std = np.mean(flatness)
  
  rolloff = librosa.feature.spectral_rolloff(S=S)
  rolloff_mean = np.mean(rolloff)
  rolloff_std = np.mean(rolloff)
  
  features = [centroid_mean, centroid_std, flatness_mean, flatness_std, rolloff_mean, rolloff_std]
  
  feature_set.append(features)

feature_set = np.array(feature_set)
print(feature_set.shape)



#%%
# Manual data labeling
y = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(feature_set, y, stratify=y, test_size=0.5)


#%%
# Definig the classification machine

classifier = KNeighborsClassifier(n_neighbors=2)
#classifier = SVC(C=0.1)


#%%
# Train classifier
classifier.fit(X_train, y_train)

# Run prediction
y_pred = classifier.predict(X_test)

# Evaluate
acc = accuracy_score(y_test, y_pred)
print(acc)


#%%
from sklearn.metrics import confusion_matrix
# conf[i,j]: true is i, predicted is j
conf = confusion_matrix(y_test, y_pred)
print(conf)


#%%



