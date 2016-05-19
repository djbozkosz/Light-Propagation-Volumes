## Light Propagation Volumes
<p style="text-align: justify; text-indent: 40px;">Master's thesis focused on real-time global illumination method: Light Propagation Volumes. This technique was introduced by Crytek in 2009 and it can calculate multiple indirect light bounce in scene. LPV is usually used with local illumination shading models and Shadow Mapping. LPV calculation of global illumination consists of three steps: injection virtual points lights obtained from Reflective Shadow Maps into LPV 3D grid, propagation of light intensity in grid stored in spherical harmonics coefficients and lookup for light intensity in LPV while scene rendering.</p>
<p style="text-align: justify; text-indent: 40px;">Implementation in C++ uses Qt/SDL and OpenGL library. LPV technique is implemented in 4 variations: with geometry shaders or compute shaders and both variants uses propagation method gathering or scattering. LPV uses 4 cascades with size 32<sup>3</sup> and Shadow Maps uses 6 cascades. Minimum HW requirements are: GPU with support OpenGL 3.2+ (D3D 10 comparable) for implementation with geometry shaders or OpenGL 4.3+ (D3D 11 comparable) for implementation with compute shaders.</p>

<img src="http://s32.postimg.org/nc56xyssl/lpv_git00.jpg" alt="Sponza">
<img src="http://s32.postimg.org/9np6wbww5/lpv_git01.jpg" alt="Sponza">
<img src="http://s32.postimg.org/4p69vjih1/lpv_git02.jpg" alt="Sponza">

<!--<img src="http://s30.postimg.org/thk683amp/teaser00.jpg" alt="Sponza">
<img src="http://s30.postimg.org/401rohswh/teaser01.jpg" alt="Sponza">
<img src="http://s30.postimg.org/4quhu9v9t/teaser02.jpg" alt="Sponza">-->
