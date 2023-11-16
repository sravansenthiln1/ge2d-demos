# Amlogic GE2D Demos

Examples to use Amlogic GE2D 2D graphics platform.

Compatible with VIM3/3L/1S/4;

GE2D Capabilities:
* max 8192px x 8192px x 4 planes, source(s) and destination canvas size
* RGB, YUV data types of 16, 24, 32 bit depth
* Uses ion-mem, or dma-mem (with ge2d_cma_reserved)
* Operation types:
    * Blend (eg. alpha image operations)
    * Blit (no scaling, eg. cropping) 
    * Stretchblit (scaled operation, eg. resize)
    * Fillrectangle (drawing pixels on canvas)

### Try Examples:

* [GE2D ionbuf](src/ge2d-ionbuf/) - process operations through ION-BUF allocated memory

* [GE2D dmabuf](src/ge2d-dmabuf/) - process operations through GE2D-DMA allocated memory

* [GE2D crop](src/ge2d-crop/) - crop from the bottom left of the image

* [GE2D cvt](src/ge2d-cvt/) - convert the image from RGBA8888 to NV12 color format

* [GE2D rotate](src/ge2d-rotate) - rotate the image 

* [GE2D resize](src/ge2d-resize/) - resize the image

* [GE2D blend](src/ge2d-blend/) - perform alpha blend operation over the image
