# FDF

This is the README for my FDF project in 42. The project requires the MLX42 library, GLFW, and specific configuration steps to run successfully.

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Configuration](#configuration)
- [Building the Project](#building-the-project)
- [Running the Program](#running-the-program)
- [Controls](#controls)
- [Images](#images)

## Requirements

Before running this project, ensure that you have the following dependencies:

- MLX42 library (clone from [GitHub](https://github.com/codam-coding-college/MLX42#download-and-build---mlx42) or `git clone https://github.com/codam-coding-college/MLX42.git`)
- GLFW library (install via `brew install glfw`)

## Installation

To install the necessary dependencies, follow these steps:

1. Clone the MLX42 library into the project repository by either of the following methods:
   - [Download and build MLX42](https://github.com/codam-coding-college/MLX42#download-and-build---mlx42)
   - Run `git clone https://github.com/codam-coding-college/MLX42.git`

2. Install GLFW library using Homebrew by running the following command:

   ```brew install glfw```

## Configuration

After installing the required dependencies, you need to configure the project by editing the path to your Homebrew installation in the makefile. Follow the steps below:

1. Locate the makefile in the root directory of the project.
2. Change the path to the headerfiles of MLX42 in l.27 `<INCLUDES>`.
3. Change the path to the GLFW lib in l.31 `<GLFW>`.
4. Change the path to the MLX archive in l.33 `<MLX>`.
5. Save and close the makefile.

## Building the Project

To build the project, navigate to the root directory of the project in the terminal and run ```make```

## Running the Program

To execute the program, use the following command:

```./fdf <path_to_map_file>```

Replace `<path_to_map_file>` with the path to the map file you want to visualize. For example:

```./fdf maps/10-2.fdf```

Maps are located in the maps folder

Make sure to provide a valid path to an existing map file as a parameter when running the program.

## Controls

Use the following controls to interact with the projection:

- `Numpad 9`: Rotate clockwise
- `Numpad 7`: Rotate counterclockwise
- `WASD`: Move the projection around
- `=`: Increase the 'Z' height
- `/`: Decrease the 'Z' height
- `Numpad 1`: Reset to isometric form
- `Numpad 3`: Reset to parallel form
- `Numpad 4`: Tilt to the left side
- `Numpad 6`: Tilt to the right side
- `Numpad 8`: Forward tilting
- `Numpad 2`: Backward tilting
- `+`: Zoom in
- `-`: Zoom out
- `Esc`: Quit the program

## Images

![Julia.fdf](/pictures/Julia.png)

![t1.fdf](/pictures/t1.png)

![elem-fract.fdf](/pictures/elem-fract.png)
