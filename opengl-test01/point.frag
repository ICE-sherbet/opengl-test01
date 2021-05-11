#version 150 core
#extension GL_ARB_explicit_attrib_location: enable
in vec4 vertex_color;
layout (location = 0) out vec4 fragment;
void main()
{
 fragment = vertex_color;
}