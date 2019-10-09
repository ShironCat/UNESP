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
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans


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
n_means=2
kmeans = KMeans(n_clusters=n_means, random_state=0)
kmeans.fit(feature_set)


#%%
# Scale data so all dimensions have zero mean and variance one.
scaler = StandardScaler()
scaled_features = scaler.fit_transform(feature_set)
scaled_centers = scaler.transform(kmeans.cluster_centers_)

# PCA data visualization
pca = PCA(n_components=2)

pca.fit(scaled_features)
projection = pca.transform(scaled_features)
centers = pca.transform(scaled_centers)


plt.figure(figsize=(10,10))
plt.grid(color='gray', linestyle=':', linewidth=1)

for i in range(projection.shape[0]):
    plt.scatter(projection[i,0], projection[i,1], color='b', label=filenames[i])


for i in range(n_means):
    plt.scatter(centers[i,0], centers[i,1], color='r')

plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')

plt.show()


#%%
# Scale data so all dimensions have zero mean and variance one.
scaler = StandardScaler()
scaled_features = scaler.fit_transform(feature_set)
scaled_centers = scaler.transform(kmeans.cluster_centers_)

# Visualizacao de dados usando PCA
pca = PCA(n_components=2)

pca.fit(scaled_features)
projection = pca.transform(scaled_features)
centers = pca.transform(scaled_centers)


plt.figure(figsize=(10,10))
plt.grid(color='gray', linestyle=':', linewidth=1)

cluster_colors=['r', 'b', 'm', 'g']
for i in range(projection.shape[0]):
    point_color = cluster_colors[ kmeans.labels_[i] ]
        
    plt.scatter(projection[i,0], projection[i,1], color=point_color, label=filenames[i])


plt.legend()
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')

plt.show()


#%%



#%%



