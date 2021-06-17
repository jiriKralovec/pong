# What is this
Quite simply - a Pong! clone made using OpenGL for learning purposes. The project leverages libraries such as GLEW, GLFW, and GLM
from various authors.

# What is the purpose of the project
The purpose is to build an application while also thinking about scalability and larger project structure. Though Pong! could very
easily be composed of three rectangles and the code could therefore be much simple, that is not really the point of this project.

The point is to arrive at a structure which will be scalable going forward and it will be possible to re-use it for other smaller game projects,
perhaps even develop a scripting language support for languages such as Lua.

## What are the limitations
By design, the current implementation only allows one shader per application as using multiple shaders is not in scope. In future,
there might be updates that will allow this, however at this point that is not the focus.