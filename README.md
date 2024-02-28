# Perlin Noise Generator

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/MdAfrozAlam8/MazeGenerator-CPP-Raylib.svg?style=flat&label=Star)](https://github.com/MdAfrozAlam8/MazeGenerator-CPP-Raylib/stargazers)

This project implements **Perlin noise** in C++ and visualizes it using the **Raylib** library. Perlin noise is a mathematical technique for generating procedural textures with smooth variations, commonly used in creating realistic-looking landscapes, clouds, and other natural phenomena in computer graphics.

## Table of Contents

- [Perlin Noise Generator](#perlin-noise-generator)
	- [Table of Contents](#table-of-contents)
	- [This project demonstrates](#this-project-demonstrates)
	- [Screenshot](#screenshot)
	- [Getting Started](#getting-started)
		- [Prerequisites](#prerequisites)
		- [Installation](#installation)
	- [Usage](#usage)
	- [Contributing](#contributing)
	- [License](#license)

## This project demonstrates
* **Perlin noise generation:** The code implements the Perlin noise algorithm, calculating noise values based on input coordinates.
* **Raylib integration:** The generated noise values are used to create a visual representation using Raylib's drawing and windowing functionalities.

## Screenshot
* 1D Perlin Noise
  ![1D Perlin Noise!](/assets/perlin_noise_1d.png)

* 2D Perlin Noise
  ![2D Perlin Noise!](/assets/perlin_noise_2d.png)

## Getting Started
### Prerequisites
* **C++ compiler:** Ensure you have a C++ compiler installed (e.g., GCC, Clang).
* **Raylib:** Download and install Raylib from https://github.com/raysan5/raylib. Follow the installation instructions for your platform.
### Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/2G-Afroz/perlin-noise
   ```
2. **Navigate to the project directory:**
   ```bash
   cd perlin-noise
   ```
3. **Build the project:**
   ```bash
   cmake -B builds
   ```
4. **Build using your preferred method:**
   1. Windows:
      	```batch
	  	cd builds
	  	mingw32-make
	  	```
   2. Linux/macOS:
    	```batch
	   	cd builds
	   	make
	   	```

## Usage
Run the generated executable (e.g., ```builds/perlin-noise.exe```).

## Contributing
Contributions are welcome! Please read [CONTRIBUTING.md](./CONTRIBUTING.md) for details on how to contribute to this project.

## License
Distributed under the MIT License. See [LICENSE](./LICENSE) for more information.