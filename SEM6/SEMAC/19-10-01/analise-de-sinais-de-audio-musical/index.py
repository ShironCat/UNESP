# To add a new cell, type '#%%'
# To add a new markdown cell, type '#%% [markdown]'
#%% [markdown]
# # Workshop: Introduction to Computer-Assisted Audio Analysis
# 
# 
#%% [markdown]
# ## What is this?
# 
# This is a set of Jupyter Notebooks and example audio files that will be used in the Introduction to Computer-Assisted Audio Analysis workshop. By the end of the workshop, you will:
# 
# 1. *Understand* how audio (and other signals) are represented within your computer (spoiler: they use arrays)
# 1. *Use and interpret* the Discrete Fourier Transform (DFT) and the Short-Time Fourier Transform (STFT), and adequately *set their parameters*
# 1. *Understand* the meaning of low-level audio features and their statistics
# 1. *Visualize* spaces spanned by low-level audio features (spoiler: using PCA)
# 1. *Use* and *interpret* the results of automatic clustering algorithms (spoiler: using K-Means)
# 
# This material should get you a good headstart on automated audio analysis.
# 
#%% [markdown]
# ## Computer setup
# 
# This workshop requires the following packages:
# 
# * matplotlib
# * numpy
# * librosa
# * sklearn
# 
# You can run the code below to check if all packages are correctly installed. If you need to install something, use your package manager - you are probably using either *pip* or *anaconda* (I am writing this in 2019).

#%%
matplotlib_installed = True
numpy_installed = True
librosa_installed = True
sklearn_installed = True

try:
    import matplotlib
except:
    matplotlib_installed = False

try:
    import numpy
except:
    numpy_installed = False

try:
    import librosa
except:
    librosa_installed = False
          
try:
    import sklearn
except:
    sklearn_installed = False

if matplotlib_installed:
    print("matplotlib is installed")
else:
    print("matplotlib is NOT installed")

if numpy_installed:
    print("numpy is installed")
else:
    print("numpy is NOT installed")

if librosa_installed:
    print("librosa is installed")
else:
    print("librosa is NOT installed")

if sklearn_installed:
    print("sklearn is installed")
else:
    print("sklearn is NOT installed")
#%% [markdown]
# ## Lesson index
# 
# Please, follow the lesson index to reach the next steps:
# 
# * [00 - Prologue](00_prologue.ipynb): how to use Python arrays, represent time series, and to plot signals and their DFTs
# * [01 - Introduction](01_intro.ipynb): how to visualize audio files and their spectrograms
# * [02 - Features](02_features.ipynb): how to interpret and visualize audio features, and how to project audio files into a content-meaningful Euclydean space
# * [03 - Visualization](03_visualization.ipynb): how to use PCA to visualize high-dimensional feature spaces
# * [04 - Clustering](04_clustering.ipynb): how to automatically split your audio files into 
# * [05 - Visualization](03_visualization.ipynb): how to use PCA to visualize high-dimensional feature spaces

#%%


