3D Maze
Creating a 3D maze with raycasting using C++ and SDL2

textured_1
Table of Content
Purpose
Inspiration
Data Flow
Environment
Installation
Usage
To-Do
Challenges
Contributing
Related Projects
Resources
Authors
License

Disable textures: ./maze no_tex or ./maze maps/<map_name> no_tex
Usage
This 3D maze uses raycasting to draw the maze walls, utilizing LodeV's method of using vectors to calculate ray length. By default the maze uses textures but textures can be disabled on execution.

Controls
W or ↑ : move forward
S or ↓ : move backward
A or ← : rotate camera left
D or → : rotate camera right
Q : strafe left
E : strafe right
F : toggle fullscreen
ESC : quit
textured_3

Map Example:

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 2 2 2 2 0 0 0 0 3 0 3 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 3 0 0 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 2 0 2 2 0 0 0 0 3 0 3 0 3 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 5 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Clone the project to your own machine
Commit changes to your own branch
Push your work back up to your fork
Submit a Pull request so that I can review your changes
NOTE: Be sure to merge the latest from "upstream" before making a pull request!

 
Resources
SDL2 API
LazyFoo Beginning Game Programming
Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi
LodeV Raycasting Tutorial
Game Engine Black Book

For our 3D maze game project, we chose to use C, SDL2, and raycasting, each for specific reasons that aligned with our project goals and constraints.

Programming Language: C
We opted for C as our programming language because of its performance and low-level memory management capabilities. C allowed us to write efficient and fast code, which is crucial for real-time game development where performance can significantly impact the user experience. Additionally, using C gave us the opportunity to deepen our understanding of pointers, memory allocation, and other fundamental programming concepts.

Graphics Library: SDL2
For handling graphics and input, we chose SDL2 (Simple DirectMedia Layer 2). SDL2 is a versatile and powerful library that provides low-level access to audio, keyboard, mouse, and graphics hardware. It supports multiple platforms, making it a great choice for developing a cross-platform game. SDL2's straightforward API allowed us to handle window creation, rendering, and event management efficiently. Moreover, SDL2's active community and extensive documentation were invaluable resources during development.

Rendering Technique: Raycasting
We used raycasting as our rendering technique to create the 3D perspective of the maze. Raycasting is a relatively simple and efficient method for rendering 3D environments from a 2D map, making it well-suited for our project scope. This technique allowed us to implement the game logic and rendering pipeline without requiring the complexity of a full 3D graphics engine. By using raycasting, we could focus on understanding the mathematics behind 3D rendering and gain insights into the principles of computer graphics.

