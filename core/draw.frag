#version 400
out vec4 frag_colour;
uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;
void main() {
vec2 st = gl_FragCoord.xy/u_resolution;
frag_colour = vec4(st.x, st.y, 0.01*(u_time + u_mouse.x), 1.0);
}
