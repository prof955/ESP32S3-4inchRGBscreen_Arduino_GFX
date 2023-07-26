#ifndef _ARDUINO_UNOPAR8_H_
#define _ARDUINO_UNOPAR8_H_

#include "Arduino_DataBus.h"

// for MCUFriend UNO kind of shields. -jz-

class Arduino_UNOPAR8 : public Arduino_DataBus
{
public:
  Arduino_UNOPAR8(int8_t dc = A2, int8_t cs = A3, int8_t wr = A1, int8_t rd = A0); // Constructor

  bool begin(int32_t speed = GFX_NOT_DEFINED, int8_t dataMode = GFX_NOT_DEFINED) override;
  void beginWrite() override;
  void endWrite() override;
  void writeCommand(uint8_t) override;
  void writeCommand16(uint16_t) override;
  void write(uint8_t) override;
  void write16(uint16_t) override;
  void writeRepeat(uint16_t p, uint32_t len) override;
  void writePixels(uint16_t *data, uint32_t len) override;

  void writeC8D8(uint8_t c, uint8_t d) override;
  void writeC8D16(uint8_t c, uint16_t d) override;
  void writeC8D16D16(uint8_t c, uint16_t d1, uint16_t d2) override;
#if !defined(LITTLE_FOOT_PRINT)
  void writeBytes(uint8_t *data, uint32_t len) override;
#endif
protected:
private:
  INLINE void WRITE(uint8_t d);
  INLINE void DC_HIGH(void);
  INLINE void DC_LOW(void);
  INLINE void CS_HIGH(void);
  INLINE void CS_LOW(void);

  int8_t _dc, _cs, _wr, _rd;
  uint8_t _port;

#ifdef __AVR__
  PORTreg_t _dcPort;                 ///< PORT register for data/command
  ARDUINOGFX_PORT_t _dcPinMaskSet;   ///< Bitmask for data/command SET (OR)
  ARDUINOGFX_PORT_t _dcPinMaskClr;   ///< Bitmask for data/command CLEAR (AND)

  PORTreg_t _csPort;                 ///< PORT register for data/command
  ARDUINOGFX_PORT_t _csPinMaskSet;   ///< Bitmask for data/command SET (OR)
  ARDUINOGFX_PORT_t _csPinMaskClr;   ///< Bitmask for data/command CLEAR (AND)

  PORTreg_t _wrPort;                 ///< PORT register for data/command
  ARDUINOGFX_PORT_t _wrPinMaskSet;   ///< Bitmask for data/command SET (OR)
  ARDUINOGFX_PORT_t _wrPinMaskClr;   ///< Bitmask for data/command CLEAR (AND)

  PORTreg_t _rdPort;                 ///< PORT register for data/command
  ARDUINOGFX_PORT_t _rdPinMaskSet;   ///< Bitmask for data/command SET (OR)
  ARDUINOGFX_PORT_t _rdPinMaskClr;   ///< Bitmask for data/command CLEAR (AND)

  PORTreg_t _dataPort_B;             ///< PORT register for data/command, bits 0..1
  PORTreg_t _dataPort_D;             ///< PORT register for data/command, bits 2..7
#endif // #ifdef __AVR__
};

#endif // _ARDUINO_UNOPAR8_H_
