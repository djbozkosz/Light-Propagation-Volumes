#version 150
precision lowp float;

in float _vertexPosition;

flat out int vertexID;

void main()
{
  vertexID = gl_VertexID;
  gl_Position = vec4(_vertexPosition);
}
