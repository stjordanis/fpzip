#ifndef PC_DECODER_H
#define PC_DECODER_H

#include "types.h"
#include "pccodec.h"
#include "pcmap.h"
#include "rcdecoder.h"
#include "rcmodel.h"

template <typename T, class M = PCmap<T>, bool wide = (M::bits > PC_BIT_MAX)>
class PCdecoder {
public:
  PCdecoder(RCdecoder* rd, RCmodel*const* rm);
  ~PCdecoder();

  // decode a value with prediction and optional context
  T decode(T pred, uint context = 0);

  // number of symbols (needed by probability modeler)
  static const uint symbols;
};

#include "pcdecoder.inl"

#endif
