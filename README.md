## Light Propagation Volumes
[![FIT VUT: Master's Thesis](https://img.shields.io/badge/fit%20vut-master's%20thesis-lightgrey.svg)](http://www.fit.vutbr.cz/study/DP/DP.php.en?id=18581)
[![Platform: Windows | Linux](https://img.shields.io/badge/platform-windows%20%7C%20linux-lightgrey.svg)](https://github.com/djbozkosz/Light-Propagation-Volumes/blob/master/Makefile)
[![C++: 0x](https://img.shields.io/badge/c++-0x-brightgreen.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![OpenGL: 3.2 | 4.3](https://img.shields.io/badge/opengl-3.2%20%7C%204.3-brightgreen.svg)](https://www.google.com/search?q=gpu+drivers)
[![MinGW: 5.3](https://img.shields.io/badge/mingw-5.3-green.svg)](https://nuwen.net/mingw.html)
[![Qt: 5](https://img.shields.io/badge/qt-5-green.svg)](https://www.qt.io)
[![SDL: 2.0](https://img.shields.io/badge/sdl-2.0-green.svg)](https://www.libsdl.org)
[![GLM: 0.9.7](https://img.shields.io/badge/glm-0.9.7-green.svg)](http://glm.g-truc.net)
[![License: GPL v3](https://img.shields.io/badge/license-GPL%20v3-blue.svg)](https://github.com/djbozkosz/Light-Propagation-Volumes/blob/master/LICENSE)
<p style="text-align: justify; text-indent: 40px;">Master's thesis focused on real-time global illumination method: Light Propagation Volumes. This technique was introduced by Crytek in 2009 and it can calculate multiple indirect light bounce in scene. LPV is usually used with local illumination shading models and Shadow Mapping. LPV calculation of global illumination consists of three steps: injection virtual points lights obtained from Reflective Shadow Maps into LPV 3D grid, propagation of light intensity in grid stored in spherical harmonics coefficients and lookup for light intensity in LPV while scene rendering.</p>
<p style="text-align: justify; text-indent: 40px;">Implementation in C++ uses Qt/SDL and OpenGL library. LPV technique is implemented in 4 variations: with geometry shaders or compute shaders and both variants uses propagation method gathering or scattering. LPV uses 4 cascades with size 32<sup>3</sup> and Shadow Maps uses 6 cascades.</p>

### Thesis:
<p>Text available on <a href="http://www.fit.vutbr.cz/study/DP/DP.php.en?id=18581" target="_blank">FIT VUT page</a>. Direct <a href="http://www.fit.vutbr.cz/study/DP/DP.php?id=18581&file=t" target="_blank">link</a>.</p>

### Hardware requirements
<p>GPU with support OpenGL 3.2+ (D3D 10 comparable) for implementation with geometry shaders or OpenGL 4.3+ (D3D 11 comparable) for implementation with compute shaders.</p>

### Video:
<p><a href="https://www.youtube.com/watch?v=dE6r0-MfyRI" target="_blank"><img src="https://s32.postimg.cc/68vkbgyf9/lpv_git04.jpg" alt="Sponza"></a></p>

### Images:
<img src="https://s32.postimg.cc/nc56xyssl/lpv_git00.jpg" alt="Sponza">
<img src="https://s32.postimg.cc/9np6wbww5/lpv_git01.jpg" alt="Sponza">
<img src="https://s32.postimg.cc/4p69vjih1/lpv_git02.jpg" alt="Sponza">

<!--<img src="https://s30.postimg.cc/thk683amp/teaser00.jpg" alt="Sponza">
<img src="https://s30.postimg.cc/401rohswh/teaser01.jpg" alt="Sponza">
<img src="https://s30.postimg.cc/4quhu9v9t/teaser02.jpg" alt="Sponza">-->
