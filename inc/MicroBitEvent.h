#ifndef MICROBIT_EVENT_H
#define MICROBIT_EVENT_H

#include "MicroBit.h"

/**
  * Class definition for a MicrobitEvent
  * It represents a common event that is generated by the various components on the MB.
  */
class MicroBitEvent
{
    public:

    //These are public at the moment for backwards compatability with old code
    //will be refactored in the future!
    
    uint16_t source;         // ID of the MicroBit Component that generated the event e.g. MICROBIT_ID_BUTTON_A. 
    uint16_t value;          // Component specific code indicating the cause of the event.
    uint32_t timestamp;      // Time at which the event was generated. ms since power on.

    /**
      * Constructor. 
      * @param src ID of the MicroBit Component that generated the event e.g. MICROBIT_ID_BUTTON_A.
      * @param value Component specific code indicating the cause of the event.
      * @param fire whether the event should be fire immediately upon construction
      * 
      * Example:
      * @code 
      * MicrobitEvent evt(id,MICROBIT_BUTTON_EVT_CLICK,true); // auto fire
      * @endcode
      */
    
    MicroBitEvent(uint16_t source, uint16_t value, bool fire = true);  
    
    /**
      * Default constructor - initialises all values, and sets timestamp to the current time.
      */ 
    MicroBitEvent(); 

    /**
      * Fires the represented event onto the message bus.
      */
    void fire();
};



#endif

