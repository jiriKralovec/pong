#version 330 core
layout (location = 0) in vec3 aPos;
out gl_PerVertex { vec4 gl_Position; };
void main()
{
    gl_Position = vec4(aPos, 1.0);
}

/*
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
*/