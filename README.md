# DailyWallpapers <img src="dailyWallpapersIcon.png" style="width: 50px; height: 50px;">

Console application that checks Bing's api for new daily images, and sets them as desktop wallpapers.

![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)


## Table of Contents

1. [How To Install](#how-to-install)
2. [Adding to Startup](#adding-to-startup)
3. [Info](#info)


### How To Install

Simple and easy installation. Head over to <a href="https://github.com/aisyshk/DailyWallpapers/releases/latest">the latest release</a> and download the `Source code (zip)`.

<img src="./docs/srccd.png" />


Once downloaded, unzip the `DailyWallpapers-xxxx.x.xx.zip`, open it until you reach the folder with the `.exe`

<img src="./docs/dl1.png" /> <img src="./docs/dl2.png" />



### Adding to Startup


If you'd like, move the `DailyWallpapers` folder to your `C:/` drive or your desktop. Open the folder with the `.exe` and create a shortcut to the `.exe`.

<img src="./docs/shtcut.png" />

To add it to startup, press `Windows Key` + `R`, then type `shell:startup`. Drag and drop the shortcut you made into the startup folder.

<img src="./docs/strtup.png" />

Before launching the app, set it to run as administrator. To do that, right click the `.exe`, click `Properties` then head over to `Compatibility` and tick `Run this program as an administrator`

<img src="./docs/propMenu.png" />

<img src="./docs/compMenu.png" />

**Why do I need to launch it as admin?** This allows the app to download and set your wallpaper without any errors, such as missing permission to download or set wallpaper.

And that's it! You've downloaded and set the app to run on startup


### Info 

⚠️ There might be a chance that the Windows Anti-Virus deletes the file under the false threat of 'Trojan' virus. I assure you the program does nothing harmful, as you can see from the code in the <a href="https://github.com/aisyshk/DailyWallpapers/tree/master">master branch</a>.
