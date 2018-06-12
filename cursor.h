#ifndef CURSOR_H
#define CURSOR_H

#define CURSOR_DEFAULT_X 64
#define CURSOR_DEFAULT_Y 16
#define CURSOR_INCREMENT 16

namespace cursor {
  void loop ();

  PROGMEM const uint8_t cursorImagePlusMask[] = {
    16, 16,
    0x00, 0x1f, 0x0e, 0x1f, 0x02, 0x1f, 0x02, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x07, 0x02, 0x1f, 0x0e, 0x1f, 0x00, 0x1f, 
    0x00, 0xf8, 0x70, 0xf8, 0x40, 0xf8, 0x40, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x40, 0xe0, 0x40, 0xf8, 0x70, 0xf8, 0x00, 0xf8,
  };
}

#endif
