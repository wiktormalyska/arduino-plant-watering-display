# Arduino Pland Watering Display
## What has beed used:
- [1x Arduino Uno R4 WiFi](https://botland.com.pl/arduino-seria-podstawowa-oryginalne-plytki/23292-arduino-uno-r4-wifi-abx00087-7630049204591.html)
- [1x Bread Board](https://botland.com.pl/plytki-stykowe/19943-plytka-stykowa-justpi-830-otworow-5904422328610.html)
- [4x Ground Moisture Detector](https://botland.com.pl/czujniki-wilgotnosci/1588-czujnik-wilgotnosci-gleby-5904422368289.html)
- [1x E-paper E-Ink 1.54" Display](https://botland.com.pl/wyswietlacze-e-paper/9098-e-paper-e-ink-154-v21-200x200px-modul-z-wyswietlaczem-spi-waveshare-12955-5904422312497.html)
- [1x Cables](https://botland.com.pl/przewody-polaczeniowe/19946-zestaw-przewodow-polaczeniowych-justpi-20cm-3x40szt-m-m-z-z-m-z-120szt-5904422328702.html)

## How does it look?
Arduino reads from ground moisture detectors hopw wet the ground is. Then those numbers are converted to percentage (not acuratelly) and then the bars hight is calculated. Finally everything is beeing shown on the display. Code is made for 4 plants, you can connect less, but you will have random numbers on bars

## FAQ
- How did you get this idea?: I just forgot to water my plants and they almost dried up.
- Did you code everything by yourself?: Every line of code is done by be (excluding libraries and parts taken from demo)

## Roadmap
- 3D printed frame for components
- exchanging arduino to smaller one
- IoT management
- Ability to set your own amount of plants

## Photos
- <img title="a title" alt="Electronics" src="/images/3.jpg">
- <img title="a title" alt="Screen" src="/images/2.jpg">
- <img title="a title" alt="Plant" src="/images/1.jpg">
