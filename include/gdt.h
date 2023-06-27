#ifndef __GDT_H
#define __GDT_H

#include "common/types.h"

class GlobalDescriptorTable
{
  public:
    class SegmentDescriptor
    {
        private:
          ostypes::common::uint16_t limit_lo;
          ostypes::common::uint16_t base_lo;
          ostypes::common::uint8_t base_hi;
          ostypes::common::uint8_t type;
          ostypes::common::uint8_t limit_hi;
          ostypes::common::uint8_t base_vhi;

        public:
          SegmentDescriptor(ostypes::common::uint32_t base, ostypes::common::uint32_t limit, ostypes::common::uint8_t type);
          ostypes::common::uint32_t Base();
          ostypes::common::uint32_t Limit();
    } __attribute__((packed));

  private:
    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;

  public:
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();

    ostypes::common::uint16_t CodeSegmentSelector();
    ostypes::common::uint16_t DataSegmentSelector();
};

#endif
