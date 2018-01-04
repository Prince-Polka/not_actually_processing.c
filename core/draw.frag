#version 400
out vec4 frag_colour;
uniform vec2 u_resolution;
uniform float u_time;
void main() {
vec2 st = gl_FragCoord.xy/u_resolution;
frag_colour = vec4(st.x, st.y, u_time, 1.0);
}
