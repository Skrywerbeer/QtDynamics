# QtDynamics
An unofficial plugin for QML to aid in creating physics based animations.
![screenshot_SolarSystem_8-2-2024](https://github.com/Skrywerbeer/QtDynamics/assets/25556420/285e9a34-f754-4197-90fe-68658d9bbcd4)
## Building
```
git clone https://github.com/Skrywerbeer/QtDynamics.git
mkdir build
cmake .. CMAKE_PREFIX_PATH=/path/to/qt6
make
```
And add the built plugin to your qml import path.
`
export QML2_IMPORT_PATH=$QML2_IMPORT_PATH:$(pwd)/imports
`

## Usage
Check the demos for usage examples.




