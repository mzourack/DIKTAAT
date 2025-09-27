#include <Arduino.h>
#include <EEPROM.h>

/* ----------Pin Addresses---------- */
//Shift register in and out pins
const uint8_t In1 = 2;
const uint8_t In2 = 9; 
const uint8_t Out1 = 6;
const uint8_t Out2 = 14;
const uint8_t Out3 = 10;
const uint8_t Out4 = 17;

// Step and group addresses
const uint8_t buttonLED1step = 5;
const uint8_t buttonLED1group = 2;
const uint8_t buttonLED2step = 6;
const uint8_t buttonLED2group = 1;
const uint8_t buttonLED3step = 4;
const uint8_t buttonLED3group = 1;
const uint8_t buttonLED4step = 1;
const uint8_t buttonLED4group = 1;
const uint8_t buttonLED5step = 6;
const uint8_t buttonLED5group = 2;
const uint8_t buttonLED6step = 5;
const uint8_t buttonLED6group = 1;
const uint8_t buttonLED7step = 3;
const uint8_t buttonLED7group = 1;
const uint8_t buttonLED8step = 2;
const uint8_t buttonLED8group = 1;
const uint8_t submodeLEDSstep[4] = { buttonLED1step, buttonLED2step, buttonLED3step, buttonLED4step };
const uint8_t submodeLEDSgroup[4] = { buttonLED1group, buttonLED2group, buttonLED3group, buttonLED4group };
const uint8_t ptrnLEDSstep[4] = { buttonLED5step, buttonLED6step, buttonLED7step, buttonLED8step };
const uint8_t ptrnLEDSgroup[4] = { buttonLED5group, buttonLED6group, buttonLED7group, buttonLED8group };

const uint8_t stripLED1step = 7;
const uint8_t stripLED1group = 3;
const uint8_t stripLED2step = 0;
const uint8_t stripLED2group = 3;
const uint8_t stripLED3step = 1;
const uint8_t stripLED3group = 3;
const uint8_t stripLED4step = 2;
const uint8_t stripLED4group = 3;
const uint8_t stripLED5step = 3;
const uint8_t stripLED5group = 3;
const uint8_t stripLED6step = 4;
const uint8_t stripLED6group = 3;
const uint8_t stripLED7step = 5;
const uint8_t stripLED7group = 3;
const uint8_t stripLED8step = 6;
const uint8_t stripLED8group = 3;
const uint8_t stripLEDsstep[8] = { stripLED1step, stripLED2step, stripLED3step, stripLED4step, stripLED5step, stripLED6step, stripLED7step, stripLED8step };
const uint8_t stripLEDsgroup[8] = { stripLED1group, stripLED2group, stripLED3group, stripLED4group, stripLED5group, stripLED6group, stripLED7group, stripLED8group };

const uint8_t trigLED1step = 3;
const uint8_t trigLED1group = 2;
const uint8_t trigLED2step = 0;
const uint8_t trigLED2group = 2;
const uint8_t trigLED3step = 2;
const uint8_t trigLED3group = 2;
const uint8_t trigLED4step = 7;
const uint8_t trigLED4group = 2;
const uint8_t trigLEDSstep[4] = { trigLED1step, trigLED2step, trigLED3step, trigLED4step };
const uint8_t trigLEDSgroup[4] = { trigLED1group, trigLED2group, trigLED3group, trigLED4group };

const uint8_t faderLEDstep = 1;
const uint8_t faderLEDgroup = 2;
const uint8_t RECLEDstep = 0;
const uint8_t RECLEDgroup = 1;
const uint8_t clockLEDstep = 4;
const uint8_t clockLEDgroup = 2;

const uint8_t trigOut1step = 6;
const uint8_t trigOut1group = 0;
const uint8_t trigOut2step = 3;
const uint8_t trigOut2group = 0;
const uint8_t trigOut3step = 1;
const uint8_t trigOut3group = 0;
const uint8_t trigOut4step = 0;
const uint8_t trigOut4group = 0;
const uint8_t clockOutstep = 4;
const uint8_t clockOutgroup = 0;
const uint8_t breakOutstep = 5;
const uint8_t breakOutgroup = 0;
const uint8_t resetOutstep = 2;
const uint8_t resetOutgroup = 0;
const uint8_t trigOutsStep[4] = {trigOut1step, trigOut2step, trigOut3step, trigOut4step};
const uint8_t trigOutsGroup[4] = {trigOut1group, trigOut2group, trigOut3group, trigOut4group};

const uint8_t button1step = 4;
const uint8_t button1group = 1;
const uint8_t button2step = 7;
const uint8_t button2group = 1;
const uint8_t button3step = 3;
const uint8_t button3group = 1;
const uint8_t button4step = 1;
const uint8_t button4group = 1;
const uint8_t button5step = 4;
const uint8_t button5group = 0;
const uint8_t button6step = 6;
const uint8_t button6group = 1;
const uint8_t button7step = 2;
const uint8_t button7group = 1;
const uint8_t button8step = 0;
const uint8_t button8group = 1;
const uint8_t buttonPatternStep[4] = { button5step, button6step, button7step, button8step};
const uint8_t buttonPatternGroup[4] = { button5group, button6group, button7group, button8group};
const uint8_t buttonSubmodeStep[4] = { button1step, button2step, button3step, button4step};
const uint8_t buttonSubmodeGroup[4] = { button1group, button2group, button3group, button4group};


const uint8_t buttonTrig1step = 3;
const uint8_t buttonTrig1group = 0;
const uint8_t buttonTrig2step = 1;
const uint8_t buttonTrig2group = 0;
const uint8_t buttonTrig3step = 2;
const uint8_t buttonTrig3group = 0;
const uint8_t buttonTrig4step = 0;
const uint8_t buttonTrig4group = 0;
const uint8_t buttonOptionsstep = 5;
const uint8_t buttonOptionsgroup = 1;
const uint8_t buttonResetstep = 5;
const uint8_t buttonResetgroup = 0;
const uint8_t buttonMutestep = 7;
const uint8_t buttonMutegroup = 0;
const uint8_t buttonAssignstep = 6;
const uint8_t buttonAssigngroup = 0;
const uint8_t buttonTrigstep[4] = { buttonTrig1step, buttonTrig2step, buttonTrig3step, buttonTrig4step};
const uint8_t buttonTriggroup[4] = { buttonTrig1group, buttonTrig2group, buttonTrig3group, buttonTrig4group};

const uint8_t buttonRECstep = 8;
const uint8_t buttonRECgroup = 0;
const uint8_t buttonRECpin = 15;

const uint8_t resetInstep = 8;
const uint8_t resetIngroup = 1;
const uint8_t resetInPin = 7;

const uint8_t ST_READ = 8;
const uint8_t ST_WRITE = 18;
const uint8_t SR_CLOCK = 19;

const uint8_t extClockDetection = 4;
const uint8_t fader = A2;
const uint8_t clockIn = 3;

const uint8_t freeAnalogPin = A6;

bool buttons[9][2];
bool prevButtons[9][2];
bool outs[8][4];

// ----------Variables----------

//Clocking and Sequencing
bool clockInState = 0;
bool lastClockState = 0;
uint8_t bar = 1;
uint8_t step = 0;     //counts clock ticks
uint8_t length = 64;  //clock ticks needed to play whole sequence
uint8_t settingToFlash = 0b00000000;
const uint8_t maxLength = 128;
uint8_t stepsPerLED = (length / 2) / 8;
bool newStep = LOW;
uint8_t seqStep = 0;
uint8_t clockDiv = 1;
uint8_t maxClockDiv = 8;
bool pause = false;
uint8_t clockOutCounter = 1;
uint8_t clockInCounter = 1;
bool progressClock = false;
unsigned long estimatedTempo[2] = {0, 0};
unsigned long prevClockTime = 0;
bool estimateClock = false;
bool extClockPresent;
bool extClockState;


uint8_t seqs[maxLength / 2][16] = { // Default patterns in bank 0 below
    //1           2           3           4           1           2           3           4           1           2           3           4           1           2           3           4
		{ 0b00000111, 0b00000001, 0b00000011, 0b00000001, 0b00000111, 0b00000001, 0b00000011, 0b00000000, 0b00000111, 0b00000000, 0b00000011, 0b00000001, 0b00000111, 0b00000010, 0b00000101, 0b00000110 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b00000011, 0b00000000, 0b00000000, 0b00000010, 0b00000001 },
    { 0b00000000, 0b00000000, 0b00000011, 0b00000011, 0b00000100, 0b00000000, 0b00000001, 0b00000011, 0b00000011, 0b00000000, 0b00000000, 0b00000100, 0b00000011, 0b00000000, 0b00000011, 0b00000000 },
    { 0b00000100, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001, 0b00000010, 0b00000000, 0b00000101, 0b00000010, 0b00000100, 0b00000000, 0b00000100, 0b00000101 },
    { 0b00000001, 0b00000110, 0b00000011, 0b00000001, 0b00000000, 0b00000011, 0b00000111, 0b00000000, 0b00000100, 0b00000110, 0b00000000, 0b00000001, 0b00000010, 0b00000010, 0b00000001, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000101, 0b00000000, 0b00000000, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000010, 0b00000011, 0b00000000, 0b00000010, 0b00000000 },
    { 0b00000110, 0b00000000, 0b00000011, 0b00000010, 0b00000010, 0b00000000, 0b00000001, 0b00000010, 0b00000010, 0b00000000, 0b00000000, 0b00000100, 0b00000110, 0b00000000, 0b00000100, 0b00000101 },
    { 0b00000000, 0b00000001, 0b00000111, 0b00000000, 0b00000001, 0b00000000, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000101, 0b00000011, 0b00000010, 0b00000010, 0b00000000, 0b00000000 },
    { 0b00000101, 0b00000001, 0b00000111, 0b00000011, 0b00000101, 0b00000001, 0b00000001, 0b00000010, 0b00000101, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000110, 0b00000100 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001, 0b00000000, 0b00000010, 0b00000010, 0b00000011, 0b00000000, 0b00000001, 0b00000000 },
    { 0b00000010, 0b00000000, 0b00000111, 0b00000001, 0b00000010, 0b00000000, 0b00000001, 0b00000001, 0b00000010, 0b00000000, 0b00000001, 0b00000100, 0b00000011, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000100, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001, 0b00000000, 0b00000000, 0b00000100, 0b00000111, 0b00000110, 0b00000010, 0b00000100, 0b00000101 },
    { 0b00000001, 0b00000010, 0b00000111, 0b00000001, 0b00000100, 0b00000011, 0b00000111, 0b00000000, 0b00000101, 0b00000111, 0b00000001, 0b00000000, 0b00000011, 0b00000000, 0b00000010, 0b00000000 },
    { 0b00000000, 0b00000100, 0b00000111, 0b00000010, 0b00000011, 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000010, 0b00000000, 0b00000001, 0b00000000 },
    { 0b00000100, 0b00000000, 0b00000111, 0b00000000, 0b00000010, 0b00000000, 0b00000111, 0b00000100, 0b00000000, 0b00000000, 0b00000001, 0b00000101, 0b00000100, 0b00000010, 0b00000100, 0b00000100 },
    { 0b00000000, 0b00000001, 0b00000111, 0b00000010, 0b00000111, 0b00000000, 0b00000000, 0b00000010, 0b00000001, 0b00000000, 0b00000100, 0b00000010, 0b00000001, 0b00000000, 0b00000000, 0b00000001 },
    { 0b00000111, 0b00000001, 0b00000111, 0b00000001, 0b00000111, 0b00000001, 0b00000011, 0b00000000, 0b00000110, 0b00000000, 0b00000001, 0b00000011, 0b00000110, 0b00000000, 0b00000110, 0b00000100 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000000, 0b00000010, 0b00000010, 0b00000000, 0b00000000, 0b00000001, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000001, 0b00000100, 0b00000000, 0b00000001, 0b00000001, 0b00000011, 0b00000000, 0b00000101, 0b00000110, 0b00000011, 0b00000011, 0b00000000, 0b00000000 },
    { 0b00000100, 0b00000000, 0b00000011, 0b00000010, 0b00000000, 0b00000000, 0b00000100, 0b00000011, 0b00000010, 0b00000000, 0b00000000, 0b00000011, 0b00000100, 0b00000000, 0b00000100, 0b00000100 },
    { 0b00000001, 0b00000010, 0b00000111, 0b00000001, 0b00000000, 0b00000011, 0b00000101, 0b00000000, 0b00000100, 0b00000111, 0b00000001, 0b00000010, 0b00000011, 0b00000001, 0b00000010, 0b00000001 },
    { 0b00000000, 0b00000100, 0b00000111, 0b00000000, 0b00000101, 0b00000000, 0b00000010, 0b00000001, 0b00000001, 0b00000000, 0b00000000, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000110, 0b00000000, 0b00000111, 0b00000010, 0b00000110, 0b00000000, 0b00000001, 0b00000010, 0b00000010, 0b00000000, 0b00000101, 0b00000111, 0b00000111, 0b00000011, 0b00000100, 0b00000100 },
    { 0b00000000, 0b00000001, 0b00000111, 0b00000000, 0b00000011, 0b00000000, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000010, 0b00000000, 0b00000000, 0b00000011, 0b00000000 },
    { 0b00000101, 0b00000001, 0b00000111, 0b00000011, 0b00000111, 0b00000001, 0b00000001, 0b00000010, 0b00000101, 0b00000000, 0b00000001, 0b00000011, 0b00000110, 0b00000010, 0b00000100, 0b00000100 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000010, 0b00000000, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000011, 0b00000001, 0b00000010, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000111, 0b00000011, 0b00000000, 0b00000000, 0b00000111, 0b00000011, 0b00000000, 0b00000000, 0b00000001, 0b00000110, 0b00000010, 0b00000010, 0b00000000, 0b00000001 },
    { 0b00000100, 0b00000000, 0b00000111, 0b00000100, 0b00000010, 0b00000000, 0b00000010, 0b00000001, 0b00000001, 0b00000100, 0b00000010, 0b00000111, 0b00000110, 0b00000000, 0b00000100, 0b00000100 },
    { 0b00000001, 0b00000000, 0b00000011, 0b00000001, 0b00000000, 0b00000111, 0b00000011, 0b00000000, 0b00000100, 0b00000011, 0b00000001, 0b00000000, 0b00000000, 0b00000100, 0b00000000, 0b00000010 },
    { 0b00000000, 0b00000000, 0b00000011, 0b00000010, 0b00000011, 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000000, 0b00000100, 0b00000011, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000010, 0b00000000, 0b00000011, 0b00000000, 0b00000001, 0b00000100, 0b00000001, 0b00000101, 0b00000111, 0b00000001, 0b00000100, 0b00000110 },
    { 0b00000000, 0b00000001, 0b00000011, 0b00000010, 0b00000001, 0b00000000, 0b00000000, 0b00000010, 0b00000000, 0b00000000, 0b00000010, 0b00000010, 0b00000010, 0b00000000, 0b00000010, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }
    };

bool trigsToAdd[4] = { false, false, false, false };

//Internal Clock
unsigned long stepStarted = 0;
unsigned long tempo = 50000;
bool extendedTempo = false;
const unsigned long maxTempo[2] = {30000, 10000}; // second value corresponds to extended range accesed via FN + Assign
const unsigned long minTempo[2] = {90000, 150000}; // second value corresponds to extended range accesed via FN + Assign
unsigned long clockOutStarted = 0;
bool clockOutOn = true;
unsigned long tapStarted;
int swingAmount = 1024/2;

//Tap Tempo
unsigned long prevTap;
unsigned long newTap;

// Resetting sequencer
unsigned long resetStarted = 0;
bool resetOn = false;
bool resetOnNextStep = false;

bool delayClock = false;
bool delayingClock = false;
unsigned long delayedClockTimer = 0;
const unsigned long clockDelayTime = 2000; // clock delay time

// Breakmode
uint8_t jumpTo = 0; // set seQstep to jumpTo
uint8_t jumpBy = 0; 
const uint8_t breakLengths[6] = {1, 2, 3, 4, 8, 16}; 
uint8_t breakLength = breakLengths[0];
uint8_t breakFreeze = 0b00000000;

unsigned long breakStarted = 0;
bool breakOn = false;
bool breakOnNextStep = false;

bool breakLEDon = false;

// Shred mode
bool bufferSequence = true;
const uint8_t shredSeqs[10] = {
  0b00000000,
  0b00010001,
  0b00110011,
  0b01110111,
  0b01010101,
  0b10101010,
  0b10001000,
  0b11001100,
  0b11101110,
  0b11111111};

uint8_t shredTracks[2]; // [0] - Left Side of Fader, [1] - Right Side of Fader
bool toShred[2];
uint8_t seqBuffer[maxLength/2];

// Probability mode
int probability = 1023 / 2;
const int faderDeadzone = 1023 / 6; // width of deadzone in middle of fader
// 
uint8_t probCap = 30; // % chance for change to happen, more if hasNeighbour
uint8_t neighbourParam = 2; // number of times having a neighbour increases change chance
bool probabilityActive[4] = {false, false, false, false};
uint8_t nextSeqStep = 0;
uint8_t prevSeqStep = 0;
bool hasNeighbour[4];
int diceRoll = 0;
// bool justEnteredProbability = true;

uint8_t microtimingProbability = 0b01010101; // 2 bits per channel set it's behavious, left bit for microtiming, right bit for probability
uint8_t microtimingProbabilityChanged = 0b00000000;


// X-Fade mode
uint8_t xFadePtrns[2];
// bool justEnteredXFade = false;
uint8_t xFadeStep = 0;

// Copy-Pasting
bool copying = false;
bool pasting = false;
// bool toCopy[16] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
uint16_t toCopy = 0;
uint8_t copyPtrn = 0;
uint8_t copyTrack = 0;

// Pattern variables
uint8_t activePtrn = 1;
uint8_t prevPtrn = activePtrn;

// Pattern chaining
// bool justEnteredChain = true;
uint8_t chainLength = 1;
uint8_t chainStep = 0;
uint8_t patternChain[8] = {1, 1, 1, 1, 1, 1, 1, 1};
uint8_t bankChain[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t nextPattern = 1;
uint8_t nextBank = 1;
uint8_t bankToChain = 1;
bool firstChainFilled = false;

// Bank variables
uint8_t activeBank = 0;

unsigned long flashTimer = 0;
unsigned long flashLength = 100000;
unsigned long flashStarted = 0;
const unsigned long flashFor = 1000000;
const unsigned long clockFlashLength = 10000;
bool prevFlashState = false;

// for handleRepeatedFlashTimer function
bool toFlash[8];
bool flashing[8];
bool prevToFlash[8];
unsigned long repeatedFlashTimer = 0;
unsigned long repeatedFlashStarted = 0;
bool prevRepeatedFlashState = false;

// Fill mode
uint8_t fillOrder[4] = {0, 0, 0, 0};
uint8_t filledCount = 0;  // Count of non-zero elements 
uint8_t fillIndex = 0;
uint8_t prevFillIndex = 0;
bool fillPattern[8];
uint8_t random1;
uint8_t random2;
unsigned long fillStarted = 0;  // For fader flashing in fill mode
uint8_t fillPatternStep = 0;
uint8_t fillOrderStep = 0;


// Fader variables
bool fillLEDon = false;
int faderValue;
int prevFader;
bool readFader;

//Triggers and Timing
unsigned long currentTime = 0;
unsigned long timePassed = 0;

unsigned int triggerLength = 5000;  //in micros
unsigned long trigStarted[4] = { 0, 0, 0, 0 };
bool trigON[4] = { false, false, false, false };

bool trigLights = true;
const unsigned long trigLEDlength = 50000;  //in micros

//Delay triggers
unsigned long trigDelays[4] = {0, 0, 0, 0};
unsigned long trigDelayTimer[4] = {0, 0, 0, 0};
uint8_t trigRepeatsToDo[4] = {0, 0, 0, 0};
unsigned long timePerStep;
unsigned long previousStepTime;

// Trigger button double tapping
const unsigned long doubleTap = 250000; // tolerance for double tap in micros
unsigned long prevTrigTap[4];
unsigned long newTrigTap[4];
bool doubleTappedTrig[4];
bool doubleTappedWindow[4];

// Mute
bool mute[4] = { false, false, false, false };
unsigned long prevMuteTap;
unsigned long newMuteTap;
bool doubleTappedMute = false;
bool tempMute[4] = { false, false, false, false };

//Mode
bool RECmode = false;
uint8_t activeSubmode = 0;
bool prevRECmode = false;
uint8_t prevSubmode = 0;
bool modeChanged = true;

// Options
unsigned long prevOptionsTap;
bool swingFader = false;

//Alt Modes - change the behaviour of various submodes
bool altModes[5][2];
// Alternative REC  modes on/off ([0][1]-CLEAR, [1][1]-COPY,  [2][1]-FILL, [3][1]-CHAIN,  [4][1]-Default REC Tool)
// Alternative Play modes on/off ([0][0]-BREAK, [1][0]-SHRED, [2][0]-PROB, [3][0]-X-FADE, [4][0]-Default PLAY Tool)

// Boot Options - Customize the behaviour of the module
uint8_t bootOptions = 0b00010000;
// Bit 0 - Disable the Break triggers on the Reset Out output when using the ALT mode of the Break Tool, Bit 1 - Delayed Clock Out after Reset, Bit 2 - Tool reset on REC/PLAY change, Bit 3 - Instant/Sequential Pattern and Bank switching
// bits 4-5 - Trigger length (00/01/10/11 - 1000/5000/10000/20000 micros)

//Assign function
uint8_t assignSubmode[2] = { 0 , 1}; //{ REC mode (yes or no), submode index (1-4)}
bool preAssignRECmode = RECmode;
uint8_t preAssignSubmode = activeSubmode;

//Save and Load
byte memoryByte;
byte byteToWrite;

// Function Declarations
void stripStepMeter();
void clearLEDstrip();
void clearPtrnLEDs();
void clearSubmodeLEDs();
void ptrnLEDsUpdate();
void submodeLEDsUpdate();
void fingerDrumming();
void liveTrigger();
void muteMode();
void resetNow();
void ptrnUpdate();
void submodeUpdate();
void playSeq();
void trigRecord();
void trig(int channel, bool ignoreMute = false, unsigned long trigDelay = 0, uint8_t trigRepeats = 1);
void trigClockOut();
void trigReset();
void trigBreak();
void clearSeq();
void copy();
void fill();
void chain();
void updateFillOrder();
void breakMode();
void shredMode();
void probabilityMode();
void updateAssignSubmode();
void mux();
void handleClockIn();
void handleClockOut();
void handleDelayedClock();
void handleDelayedTrigs();
void handleHeldReset();
void handleModes();
void checkDoubleTap();
void handleOptions();
void handleBanks();
void handleAltModes();
void handleMutes();
void takeDownOuts();
void refreshStates();
void handleRepeatedFlashTimer();
void save();
void load();
byte bool2bits(bool bit0 = false, bool bit1 = false, bool bit2 = false, bool bit3 = false, bool bit4 = false, bool bit5 = false, bool bit6 = false, bool bit7 = false);
bool bits2bool(byte byteBlock, int address);
void resetMCU();
void printSeqs();
void bootMenu();


void setup() {
  Serial.begin(9600);

  randomSeed(analogRead(freeAnalogPin));

  pinMode(ST_READ, OUTPUT);
  pinMode(ST_WRITE, OUTPUT);
  pinMode(SR_CLOCK, OUTPUT);

  pinMode(In1, INPUT);
  pinMode(In2, INPUT);
  pinMode(Out1, OUTPUT);
  pinMode(Out2, OUTPUT);
  pinMode(Out3, OUTPUT);
  pinMode(Out4, OUTPUT);

  pinMode(extClockDetection, INPUT);
  pinMode(buttonRECpin, INPUT_PULLUP);
  pinMode(resetInPin, INPUT);
  pinMode(clockIn, INPUT);

  mux();
    
    if (buttons[buttonResetstep][buttonResetgroup]) { // Reload factory settings by holding Reset on startup
      save();
      load();
    }
   else { 
    load();
   }
    if (buttons[buttonOptionsstep][buttonOptionsgroup]) { // Boot Menu
    for (int i = 0; i <= 8; i++)
        {
          for (int j = 0; j <= 1; j++)
          {
            prevButtons[i][j] = buttons[i][j];
          }
        }
      while (!(buttons[buttonOptionsstep][buttonOptionsgroup] > prevButtons[buttonOptionsstep][buttonOptionsgroup])) { // Boot Menu
        bootMenu();
      }
    }

    uint8_t triggerLengthToDecode = bootOptions & 0b00110000;
        switch (triggerLengthToDecode) {
          case 0b00000000:
            triggerLength = 1000;
            break;
          case 0b00010000:
            triggerLength = 5000;
            break;
          case 0b00100000:
            triggerLength = 10000;
            break;
          case 0b00110000:
            triggerLength = 20000;
            break;
        }
}

void loop() {
  mux();
  handleClockIn();
  handleHeldReset();
  handleModes();
  handleRepeatedFlashTimer();

  // Reset detection
  if (((buttons[buttonResetstep][buttonResetgroup] > prevButtons[buttonResetstep][buttonResetgroup]) && !buttons[buttonOptionsstep][buttonOptionsgroup]) || (buttons[resetInstep][resetIngroup] > prevButtons[resetInstep][resetIngroup])){
    resetNow();
  }

  // Record current time
  timePassed = micros() - currentTime;
  currentTime += timePassed;
  checkDoubleTap();
  takeDownOuts();
  // refreshStates();

  if (delayingClock) {
    handleDelayedClock();
  }

  handleDelayedTrigs();

  // Finished new step operations
  newStep = LOW;

  // Record previous button state
  for (int i = 0; i <= 8; i++) {
    for (int j = 0; j <= 1; j++) {
      prevButtons[i][j] = buttons[i][j];
    }
  }
  // Record previous pattern
  prevPtrn = activePtrn;
}

/* ----------------------------------------Functions---------------------------------------- */

void stripStepMeter() {
    clearLEDstrip();
    bar = seqStep / stepsPerLED;
    outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = HIGH;
}

void clearLEDstrip() {
      for (int i = 0; i <= 7; i++) {
        outs[stripLEDsstep[i]][stripLEDsgroup[i]] = LOW;
      }
}

void clearPtrnLEDs() {
    for (int i = 0; i <= 3; i++) {
       outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = LOW;
     }
}

void clearSubmodeLEDs() {
      for (int i = 0; i <= 3; i++) {
        outs[submodeLEDSstep[i]][submodeLEDSgroup[i]] = LOW;
      }
}

void ptrnLEDsUpdate() {
  clearPtrnLEDs();
  outs[ptrnLEDSstep[activePtrn - 1]][ptrnLEDSgroup[activePtrn - 1]] = HIGH;

  if (chainStep < (chainLength-1)) {
    nextPattern = patternChain[chainStep+1];
    }
  else {
    nextPattern = patternChain[0];
    }

  if (activePtrn != nextPattern){

    for (int i = 0; i <= 3; i++) {
      if (nextPattern == (i+1)) {outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = prevFlashState;}
    }
    if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
  }
}

void submodeLEDsUpdate() {
  clearSubmodeLEDs();
  if ((activeSubmode > 0) && (activeSubmode < 5)) {
    outs[submodeLEDSstep[activeSubmode - 1]][submodeLEDSgroup[activeSubmode - 1]] = HIGH;
  } else if (activeSubmode == 5) {
          for (int i = 0; i <= 3; i++) {
            outs[submodeLEDSstep[i]][submodeLEDSgroup[i]] = HIGH;
          }
  }
}

void fingerDrumming() {
  liveTrigger();

if (altModes[4][0]){
  for (int i = 0; i <= 3; i++) {
    tempMute[i] = buttons[buttonTrigstep[i]][buttonTriggroup[i]];
  }
  }

  // liveTrigger();
  stripStepMeter();
  ptrnUpdate();
  ptrnLEDsUpdate();
}

void liveTrigger() {
      for (int i = 0; i <= 3; i++) {
      if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] && !prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) { 
        trig(i+1, true);
        // trig(i + 1, true, 1000000/5,3);
        }
      }
}

void muteMode() {
  for (int i = 0; i <= 3; i++) {
    if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
    {
      mute[i] = !mute[i];
    }
      outs[trigLEDSstep[i]][trigLEDSgroup[i]] = !mute[i];
  }
}

void resetNow() {
    step = 0;
    clockInState = HIGH;
    lastClockState = LOW;
    stepStarted = micros();
    seqStep = 0;
    chainStep = 0;
    clockOutCounter = 1;
    clockInCounter = 1;
    activePtrn = patternChain[chainStep];
    activeBank = bankChain[chainStep];
    if (pause) {
      trigReset();
    }
    else {
      resetOnNextStep = true;
    }
    // stripStepMeter();
}

void ptrnUpdate() {
for (int i = 0; i <= 3; i++) {
      if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] && !prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) {
          if (!(bootOptions & (1 << 3))) {
            activePtrn = i + 1;
          } 
        chainLength = 1;
        chainStep = 0;
        patternChain[0] = i + 1;
        bankChain[0] = activeBank;
      }
    }
}

void submodeUpdate() {
  for (int i = 0; i <= 3; i++) {
    if (buttons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]] > prevButtons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]])
    {
      if (activeSubmode == i+1)
      {
        activeSubmode = 0;
      } else {
      activeSubmode = i+1;
    }
  }
  }
}

void playSeq() {

  if (!RECmode && activeSubmode == 1) { // Handle break mode
    if (newStep && !(step & 1) && (breakFreeze || buttons[buttonTrig1step][buttonTrig1group] || buttons[buttonTrig2step][buttonTrig2group] || buttons[buttonTrig3step][buttonTrig3group] || buttons[buttonTrig4step][buttonTrig4group])) {
      if (jumpBy < (breakLength-1)){
        jumpBy = jumpBy + 1;
      }
      else{
        jumpBy = 0;
        breakOnNextStep = true;
        
        if (fillOrder[fillOrderStep] && (fillOrderStep < 4)) {  // if the element is not zero
              fillOrderStep++;
            }
            else {
              fillOrderStep = 1;
            }
      }
  
      if (fillOrder[fillOrderStep-1]) {jumpTo = (1+(length/8)*(fillOrder[fillOrderStep-1] - 1)) + jumpBy;}
      if (jumpTo > (length / 2)) {jumpTo = jumpTo - (length / 2);} // return to start of sequence if trying to jump beyond sequence length
  
    }
    else if (newStep && !(step & 1)) {
      jumpTo = 0; jumpBy = 0; fillOrderStep = 1; 
    }
  }

  if (step & 1) {  // play the sequence on even steps
    
    flashLength = timePerStep/2; // adjust rate of flashing to avoid aliasing
    if (flashLength < 100000) {flashLength = 100000;}

    if (jumpTo) {seqStep = jumpTo - 1;}
    else{seqStep = step / 2;}

    if      (seqStep == 0)                  {prevSeqStep = (length / 2) - 1; nextSeqStep = seqStep + 1;}
    else if (seqStep == ((length / 2) - 1)) {prevSeqStep = seqStep - 1;      nextSeqStep = 0;}
    else                                    {prevSeqStep = seqStep - 1;      nextSeqStep = seqStep + 1;}

    // Take XFade into account
    if (!RECmode && (activeSubmode == 4) && xFadePtrns[1]) {
      if (length > 32) { // this way long patterns x-fade twice over their length
        if (altModes[3][0] && (chainLength > 1)) {
          activeBank = xFadePtrns[(xFadeStep) <= (seqStep & 31)] - 1;
        }
        else {
        activePtrn = xFadePtrns[(xFadeStep)<=(seqStep&31)];
        patternChain[0] = activePtrn;
        }
      }
      else {
        if (altModes[3][0] && (chainLength > 1)) {
          activeBank = xFadePtrns[(xFadeStep)<=(seqStep&15)] - 1;
        }
        else {
        activePtrn = xFadePtrns[(xFadeStep)<=(seqStep&15)];
        patternChain[0] = activePtrn;
        }
      }
    }

    bool fromSeq[4] = {seqs[seqStep][0 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[seqStep][1 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[seqStep][2 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[seqStep][3 + 4 * (activePtrn - 1)] & (1 << activeBank)};
    bool prevSeq[4] = {seqs[prevSeqStep][0 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[prevSeqStep][1 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[prevSeqStep][2 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[prevSeqStep][3 + 4 * (activePtrn - 1)] & (1 << activeBank)};
    bool nextSeq[4] = {seqs[nextSeqStep][0 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[nextSeqStep][1 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[nextSeqStep][2 + 4 * (activePtrn - 1)] & (1 << activeBank), seqs[nextSeqStep][3 + 4 * (activePtrn - 1)] & (1 << activeBank)};

    for (int i = 0; i <= 3; i ++) { // take probability into account
      hasNeighbour[i] = prevSeq[i] || nextSeq[i];
      if (probabilityActive[i] && !RECmode && !(jumpTo) && (microtimingProbability & (0b01 << (2*i)))) { // apply when not in REC mode or in break mode

        if (probability < ((1023 / 2) - (faderDeadzone / 2))) // Fader left
        {
        
          if (!altModes[2][0]) {
            diceRoll = random(-2*((1023 / 2) - (faderDeadzone / 2)), ((1023 / 2) - (faderDeadzone / 2))); // limits the max occurrence to about 33.3% 
          }
          else {
            diceRoll = random(0, ((1023 / 2) - (faderDeadzone / 2)));
          }

          if (probability <= diceRoll) {
            fromSeq[i] = false;
          }
        }
        else if (probability > ((1023 / 2) + (faderDeadzone / 2))) // Fader right
        {
          if (!altModes[2][0]) {
            diceRoll = random(((1023 / 2) + (faderDeadzone / 2)), 1024 + 2*(1023 - ((1023 / 2) + (faderDeadzone / 2)))); // limits the max occurrence to about 33.3%  
          }
          else {
            diceRoll = random(((1023 / 2) + (faderDeadzone / 2)), 1024);
          }
          if ((hasNeighbour[i] || fromSeq[i]) && (probability >= diceRoll)) {
            fromSeq[i] = !fromSeq[i];
          }          
        }

      }
    }
    
    for (int i = 0; i <= 3; i++) {
      if (fromSeq[i]) {
        unsigned long delayTrigBy = 0;
        uint8_t trigRepeats = 1;

        if (probabilityActive[i] && !RECmode && !(jumpTo) && (microtimingProbability & (0b10 << (2*i)))) { // apply when not in REC mode or in break mode

          if (probability < ((1023 / 2) - (faderDeadzone / 2))) // Fader left - microtiming
          {

            delayTrigBy = timePerStep/2;
            delayTrigBy = delayTrigBy * ((1023 / 2) - (faderDeadzone / 2) - probability)/(((1023 / 2) - (faderDeadzone / 2)));

            delayTrigBy = random(0, delayTrigBy);

          }
          else if (probability > ((1023 / 2) + (faderDeadzone / 2))) // Fader right - ratchetting
          {
            int coinToss = random((1023 / 2) + (faderDeadzone / 2), 1023*2);
            if (probability > coinToss) {
              trigRepeats = random(1, 4);
              if (trigRepeats != 1) {
                delayTrigBy = timePerStep*2/(trigRepeats+1);
              }
              else {
                delayTrigBy = timePerStep/(trigRepeats+1);
              }
              trig(i + 1);
            }
          }
        }
        
        trig(i+1, false, delayTrigBy, trigRepeats);
      }
    }
    // Estimate time per seq step
    timePerStep = currentTime - previousStepTime;
    previousStepTime = currentTime;

    if (breakOnNextStep && !resetOnNextStep) {trigBreak(); breakOnNextStep = false;}
    if (resetOnNextStep) {trigReset(); resetOnNextStep = false;}

    handleClockOut();
  }

  else {  //write recorded triggers into seqs
    int seqStep = (step / 2) - 1;
    for (int i = 0; i <= 3; i ++) {
    seqs[seqStep][i + 4 * (activePtrn - 1)] |= (((seqs[seqStep][i + 4 * (activePtrn - 1)] & (1 << activeBank)) || trigsToAdd[i]) << activeBank);
    trigsToAdd[i] = false;
    }
  }
}

void trigRecord() {  // record triggers pressed during current sequencer step into temporary memory
  liveTrigger();
  for (int i = 0; i <= 3; i++) {
    trigsToAdd[i] = trigsToAdd[i] || (buttons[buttonTrigstep[i]][buttonTriggroup[i]] && !prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]);
  }
  if (altModes[4][1]){
  for (int i = 0; i <= 3; i++) {
    tempMute[i] = buttons[buttonTrigstep[i]][buttonTriggroup[i]];
  }
  }
  stripStepMeter();
  ptrnUpdate();
  ptrnLEDsUpdate();
}

void trig(int channel, bool ignoreMute, unsigned long trigDelay, uint8_t trigRepeats)
{
  if (trigDelay > 0) {
    trigDelays[channel-1] = trigDelay;
    trigDelayTimer[channel-1] = trigDelay;
    trigRepeatsToDo[channel-1] = trigRepeats;
  }
  else {
    // send out a trigger from channel = 1/2/3/4
    trigStarted[channel - 1] = micros();
    if ((!mute[channel - 1] && !tempMute[channel - 1]) || ignoreMute)
    {
      outs[trigOutsStep[channel - 1]][trigOutsGroup[channel - 1]] = true;
      trigON[channel - 1] = true;
    }
    if (trigLights)
      {
        // outs[trigLEDSstep[channel - 1]][trigLEDSgroup[channel - 1]] = HIGH;
        outs[trigLEDSstep[channel - 1]][trigLEDSgroup[channel - 1]] = !(mute[channel - 1] || tempMute[channel - 1]);
    }
  }
}

void trigClockOut() {  //send out a clock pulse
  outs[clockOutstep][clockOutgroup] = HIGH;
  outs[clockLEDstep][clockLEDgroup] = HIGH;
  clockOutStarted = micros();
  clockOutOn = true;

    //outs[][trigLEDSgroup[channel - 1]] = HIGH;
    //clockOutLEDon = true;

}

void trigReset() {  //send out a trigger from the Reset Output and the Break Output
  outs[resetOutstep][resetOutgroup] = HIGH;
  resetStarted = micros();
  resetOn = true;

  if (!(bootOptions & (1 << 1))) {
    delayClock = true;
  }

  trigBreak();
}

void trigBreak() {  //send out a trigger from the Break Output
if (!altModes[0][0]) {
  outs[breakOutstep][breakOutgroup] = HIGH;
  }
  else if (!(bootOptions & (1 << 0)))
  {
    outs[resetOutstep][resetOutgroup] = HIGH;
  }
  breakStarted = micros();
  breakOn = true;
  breakLEDon = true;

  if (!(bootOptions & (1 << 1))) {
    delayClock = true;
  }
}

void clearSeq() {
  stripStepMeter();
  ptrnLEDsUpdate();
  bool toDelete[16];
  for (int i = 0; i <= 15; i++)
    {
      toDelete[i] = false;
    }

  if (altModes[0][1]) {
    for (int i = 0; i <= 3; i++) {
      tempMute[i] = buttons[buttonTrigstep[i]][buttonTriggroup[i]];
    }

    if (newStep && (step & 1)) {
        for (int i = 0; i <= 3; i++) {
          if (buttons[buttonTrigstep[i]][buttonTriggroup[i]]) {
            seqs[seqStep][i + 4 * (activePtrn - 1)] &= ~(1 << activeBank);
          }
        }
    }

    // Double tap trig button to clear track
    for (int i = 0; i <= 3; i++)
    {
      if (doubleTappedTrig[i]) {
        toDelete[i + 4 * (activePtrn - 1)] = true;
        toFlash[i] = true;
      }
    }
  }
  else {
    // Mark tracks in active pattern to be cleared
    for (int i = 0; i <= 3; i++)
    {
      if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] && !prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
      {
        toDelete[i + 4 * (activePtrn - 1)] = true;
        toFlash[i] = true;
      }
    }
  }


    for (int i = 0; i <= 3; i++) {
    if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] && !prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]])
      {
        for (int j = 0; j <= 3; j++)
        {
          toDelete[4 * i + j] = true;
          toFlash[4+i] = true;
        }
      }
      }

    // Clear marked tracks
    for (int i = 0; i <= 15; i++)
    {
      if (toDelete[i])
      {
        for (int j = 0; j <= (maxLength / 2 - 1); j++)
        {
          seqs[j][i] &= ~(1 << activeBank);
        }
      }
    }
}

void copy() {
  ptrnLEDsUpdate();
  // stripStepMeter();
  clearLEDstrip();
  outs[faderLEDstep][faderLEDgroup] = HIGH;

  if (modeChanged || prevButtons[buttonOptionsstep][buttonOptionsgroup]) {
    prevFader = faderValue;
    readFader = false;
    // modeChanged = false;
  }

  if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
    readFader = true;
  }

  int8_t pasteOffset = 0;

  if (readFader){  
      if (1023 - faderValue < ((1023/2)-(faderDeadzone/2))) {
        for (int j = 0; j <= 3; j++)
        {
          if (1023 - faderValue <= ((j + 1) * (1023 / 8))) {
          outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
          pasteOffset--;
          }
        }
      }
      else if (1023 - faderValue > ((1023/2)+(faderDeadzone/2))) {
        for (int j = 4; j <= 7; j++)
        {
          if (1023 - faderValue >= (j * (1023 / 8))) {
            outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
            pasteOffset++;
          }
        }
      }
  }
    
  if (!pasting) {
    copying = true;
    // for (int i = 0; i <= 15; i++) {
    //   toCopy[i] = false;
    //   copyPtrn = 0;
    // }
    toCopy = 0;
    copyPtrn = 0;
  }
  else {
    if (copyPtrn) {  // When copying from pattern
      for (int i = 0; i <= 3; i++) {

        if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
        { // Paste Track i from pattern into Track i of active pattern
          for (int j = 0; j <= (length / 2 - 1); j++)
          {
            seqs[j][4 * (activePtrn - 1) + i] = (seqs[j][4 * (activePtrn - 1) + i] & ~(1 << activeBank)) | (seqs[j][4 * (copyPtrn - 1) + i] & (1 << activeBank)); // Replacing triggers
            //seqs[j][4 * (activePtrn - 1) + i] = seqs[j][4 * (copyPtrn - 1) + i]; // before banks
          }

         toFlash[i] = true;
         toFlash[copyPtrn+3] = true;
        }
      if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]){ // Pasting pattern into Pattern i
          for (int j = 0; j <= (length / 2 - 1); j++) {
            for (int k = 0; k<=3; k++) {
              seqs[j][k+4*i] = (seqs[j][k+4*i] & ~(1 << activeBank)) | (seqs[j][4*(copyPtrn-1)+k] & (1 << activeBank)); // Replacing triggers  
            }

          }
         toFlash[i+4] = true;
         toFlash[copyPtrn+3] = true;
      }
      }
    } 
    else {  //When copying a single track
      int dest = 0;
      for (int k = 0; k <= 3; k++) {
        if (buttons[buttonTrigstep[k]][buttonTriggroup[k]] > prevButtons[buttonTrigstep[k]][buttonTriggroup[k]]) { // Paste single track to Track k
          for (int i = 0; i <= 15; i++) {
            // if (toCopy[i]) {
              if (toCopy & (1 << i)) {
              for (int j = 0; j <= (length / 2 - 1); j++) {

               if (j + pasteOffset > (length / 2 - 1)) {
                  dest = j + pasteOffset - (length / 2);
                }
                else if (j + pasteOffset < 0) {
                  dest = j + pasteOffset + (length / 2);
                }
                else {
                  dest = j + pasteOffset;
                }

                
                seqs[dest][4 * (activePtrn - 1) + k] = (seqs[j][4 * (activePtrn - 1) + k] & ~(1 << activeBank)) | (seqs[j][i] & (1 << activeBank)); // Replacing triggers

              }
            }
          }
        toFlash[k] = true;
        toFlash[copyTrack-1] = true;
        }
      if (buttons[buttonPatternStep[k]][buttonPatternGroup[k]] > prevButtons[buttonPatternStep[k]][buttonPatternGroup[k]]) {  // Paste single track to same track in Pattern i
        for (int i = 0; i <= 15; i++) {
          // if (toCopy[i]) {
            if (toCopy & (1 << i)) {
            for (int j = 0; j <= (length / 2 - 1); j++) {
              seqs[j][4*k + copyTrack - 1] = (seqs[j][4*k + copyTrack - 1] & ~(1 << activeBank)) | (seqs[j][i] & (1 << activeBank)); // Replacing triggers
              // seqs[j][4*k + copyTrack - 1] = seqs[j][i]; // before banks
            }
          }
        }
        toFlash[k+4] = true;
        toFlash[copyTrack-1] = true;
      }
      }
    }
  }

  if (copying) {
    for (int i = 0; i <= 3; i++) {
      if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
      { 
        // toCopy[4 * (activePtrn - 1) + i] = true;
        toCopy |= (1 << (4 * (activePtrn - 1) + i));
        copying = false;
        pasting = true;
        copyTrack = i + 1;
        toFlash[i] = true;
      }

    if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) {
      copying = false;
      pasting = true;
      copyPtrn = i + 1;
      toFlash[i+4] = true;
    }
    }
  }

  if (altModes[1][1] && pasting) {
    if (((copyTrack > 0) && (!buttons[buttonTrigstep[copyTrack-1]][buttonTriggroup[copyTrack-1]])) || ((copyPtrn > 0) && (!buttons[buttonPatternStep[copyPtrn-1]][buttonPatternGroup[copyPtrn-1]]))){ 
      copying = true;
      pasting = false;
      copyTrack = 0;
      copyPtrn = 0;
      // for (int i = 0; i <= 15; i++) {
      //   toCopy[i] = false;
      // }
      toCopy = 0;
    }
  }

  bar = seqStep / stepsPerLED;

  outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
  if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
}

void fill() {
  const bool fillPatterns[5][8] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {1, 0, 0, 1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0}};
  
  ptrnUpdate();
  ptrnLEDsUpdate();
  stripStepMeter();
  if (!fillLEDon) {outs[faderLEDstep][faderLEDgroup] = HIGH;}
  
  updateFillOrder();

  prevFillIndex = fillIndex;
  // fillIndex = map(faderValue-1, 0, 1023, 5, -1);
  fillIndex = map(faderValue-1, 0, 1023, 6, -1);

  bar = seqStep / stepsPerLED;

  // if (fillIndex < 4) {
  if (fillIndex < 5) {
  for (int i = 0; i <= 7; i++) {
    fillPattern[i] = fillPatterns[fillIndex][i];
  }
  }
  else {
    if ((prevFillIndex != fillIndex) || (( newStep && ((step & 0b1111) == 0)) && (!buttons[buttonTrig1step][buttonTrig1group] && !buttons[buttonTrig2step][buttonTrig2group] && !buttons[buttonTrig3step][buttonTrig3group] && !buttons[buttonTrig4step][buttonTrig4group])) || ((((buttons[buttonTrigstep[0]][buttonTriggroup[0]] < prevButtons[buttonTrigstep[0]][buttonTriggroup[0]]) || (buttons[buttonTrigstep[1]][buttonTriggroup[1]] < prevButtons[buttonTrigstep[1]][buttonTriggroup[1]]) || (buttons[buttonTrigstep[2]][buttonTriggroup[2]] < prevButtons[buttonTrigstep[2]][buttonTriggroup[2]]) || (buttons[buttonTrigstep[3]][buttonTriggroup[3]] < prevButtons[buttonTrigstep[3]][buttonTriggroup[3]])) && (!buttons[buttonTrig1step][buttonTrig1group] && !buttons[buttonTrig2step][buttonTrig2group] && !buttons[buttonTrig3step][buttonTrig3group] && !buttons[buttonTrig4step][buttonTrig4group])))) {    
      // generate new fill sequences if a new step is triggered and no button is held, or if a trigger is released and no button is held anymore
      fillPattern[0] = true;
      for (int i = 1; i <= 7; i++) {
        fillPattern[i] = false;
      }
      random1 = (random(2,8));
    // int randoms[7] = {1,2,3,4,5,6,7};
    int randoms[6] = {2,3,4,5,6,7};
    bool matchFound = false;
    uint8_t removedCount = 0;
    for (int i = 0; i <= 5; i++) {
        if  (randoms[i] == random1) {
          matchFound = true;
        }
        if (matchFound) {
          if (i == 0) {
            for (int j = 0; j <= 3; j++) {
              randoms[j] = randoms[j + 2];
            }
            removedCount = 2;
          }
          else if (i == 5) {
            removedCount = 2;
          }
          else {
            for (int j = i-1; j <= 2; j++) {
              randoms[j] = randoms[j + 3];
            }
            removedCount = 3;
          }
          matchFound = false;
        }
    }
    random2 = randoms[random(0, 6 - removedCount)];
    }
      fillPattern[random1] = true;
    if (fillIndex == 5) {
      fillPattern[random2] = true;
    }
  }

  // }


  for (int i = 0; i <= 7; i++) {
    outs[stripLEDsstep[i]][stripLEDsgroup[i]] = fillPattern[i];
  }
  outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
  if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}

  for (int i = 0; i <= 3; i++) {
    if (doubleTappedTrig[i]) {
      for (int j = 0; j <= 3; j++) {
        fillOrder[j] = 0;
      }
      int k = 0;
      for (int j = 0; j <= ((length/2) - 1); j++) {
        seqs[j][4 * (activePtrn - 1) + i] = (seqs[j][4 * (activePtrn - 1) + i] & ~(1 << activeBank)) | (fillPattern[k] << activeBank);
      if ((fillIndex == 2) && (k > 1)) {k = 0;}
      else if (k < 7) {k++;}
      else {k = 0;}
      }
    }
  }

  for (int i = 0; i <= 3; i++) {
      tempMute[i] = false;
  }

  if (fillOrder[0]) { // if some button is held, fill Order is not empty
  if (!altModes[2][1]) {
              for (int i = 0; i <= 3; i++) {
                if (fillOrder[i]) {
                  tempMute[fillOrder[i]-1] = true;
                }
              }
          }

    if (newStep && (step & 1)) {

      if (!altModes[2][1]) {
        for (int i = 0; i <= 3; i++) {
          if (fillOrder[i]) {
            seqs[seqStep][fillOrder[i] - 1 + 4 * (activePtrn - 1)] &= ~(1 << activeBank);
          }
        }
      }

      if (fillPattern[fillPatternStep-1]) {

          if (!fillOrder[fillOrderStep-1] || (fillOrderStep > 4)) {
            fillOrderStep = 1;
          }
          seqs[seqStep][fillOrder[fillOrderStep-1] - 1 + 4 * (activePtrn - 1)] |= (1 << activeBank);
          trig(fillOrder[fillOrderStep-1], true);         
          
          fillOrderStep++;  
      }

      fillPatternStep++;
      if (fillPatternStep > 8) {
        fillPatternStep = 1;
      }
      else if ((fillIndex == 2) && (fillPatternStep > 3)) {
              fillPatternStep = 1;
      }
    }
  }
  else { // refresh variables when nothing is held
    fillOrderStep = 1;
    fillPatternStep = 1;
  }
}

void chain() {
  clearLEDstrip();
  if (modeChanged)
  {
    // modeChanged = false;
    for (int i = 0; i <= 3; i++)
    {
        chainLength = 1;
        chainStep = 0;
        flashTimer = currentTime;
        prevFlashState = HIGH;
        bankToChain = activeBank;
        firstChainFilled = false;
    }
  }

    if (firstChainFilled) {
      outs[stripLEDsstep[chainLength]][stripLEDsgroup[chainLength]] = prevFlashState;
    }
    else {
      outs[stripLEDsstep[0]][stripLEDsgroup[0]] = prevFlashState;
    }

  for (int i = 0; i <= 3; i++){
    if (!altModes[3][1]) {
      outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = prevFlashState;
      if ((buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) || (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])) {
      if (firstChainFilled) {
        chainLength++;
      }
      else {
        firstChainFilled = true;
        }
      patternChain[chainLength-1] = i+1; 
      bankChain[chainLength-1] = activeBank;
      if (chainLength==8) {
        activeSubmode = 0;
      }
    }
    }
    else {
      if ((buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]])) {
        bankToChain = i;
      }
      outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = (i == bankToChain);
      if ((buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])) {
        if (firstChainFilled) {
        chainLength++;
      }
      else {
        firstChainFilled = true;
      }
      patternChain[chainLength-1] = i+1; 
      bankChain[chainLength-1] = bankToChain; 
      if (chainLength==8) {
        activeSubmode = 0;
      }
    }
    }
  }

  if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
  
  
  for (int i = 0; i <= 7; i++){
    if ((chainLength > i) && firstChainFilled){
      outs[stripLEDsstep[i]][stripLEDsgroup[i]] = HIGH;
    }
  }
}

void updateFillOrder() {
filledCount = 0;

    // Record the fill order
  for (int i=0; i <= 3; i++){
     if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]){ // if a button has been newly pressed, record it into first zero fillOrder position
       for (int j=0; j <=3; j++){
         if (!fillOrder[j]){ // if fillOrder[j] is 0, write newly pressed trig there
           fillOrder[j] = i+1;
           break;
         }
       }
     } 
  }

  for (int i=0; i <= 3; i++){
       if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] < prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) // if a trig is not pressed, write a zero instead of it in the fillOrder
        for (int j=0; j <=3; j++){
         if (fillOrder[j] == (i+1)){ // if fillOrder[j] is 0, write newly pressed trig there
           fillOrder[j] = 0;
         }
      }
  }

  for (int i=0; i <= 3; i++){ // push zero elements in fillOrder[] to the end of the array
    if (fillOrder[i] != 0) {fillOrder[filledCount++] = fillOrder[i];}  
  }
  while (filledCount <= 3) {fillOrder[filledCount++] = 0;}
}

void breakMode() {
  ptrnUpdate();
  ptrnLEDsUpdate();

  if (modeChanged)
  {
    // modeChanged = false;
    breakFreeze = 0;
    breakLength = breakLengths[1];
  }

  if (modeChanged || prevButtons[buttonOptionsstep][buttonOptionsgroup]) {
    prevFader = faderValue;
    readFader = false;
    // modeChanged = false;
  }

  if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
    readFader = true;
  }

  if (readFader) {
    breakLength = breakLengths[map(faderValue, 0, 1023, 5, 0)];
  }

  if (breakFreeze) {
    outs[breakOutstep][breakOutgroup] = HIGH;
    breakLEDon = true;  
    outs[submodeLEDSstep[0]][submodeLEDSgroup[0]] = prevFlashState;
    if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}

    for (int i = 0; i <= 3; i++) {
      fillOrder[i] = 0;
    }

    for (int i = 0; i <= 3; i++) {
      if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) {
        breakFreeze = i+1;
      }
      
      fillOrder[0] = breakFreeze;

      // Write the loop to the sequence and quit freeze and break tool
        if (doubleTappedTrig[i]) {
          doubleTappedTrig[i] = false;
          uint8_t freezeBuffer[16]; // Max break length is 16 steps
          for (int j = 0; j <= breakLength-1; j++) {
            freezeBuffer[j] = 0b00000000;
            for (int k = 0; k <= 3; k++) {
              freezeBuffer[j] |= bool(seqs[((breakFreeze - 1) * (length / (8))) + j][k + 4 * (activePtrn - 1)] & (1 << activeBank)) << k;
            }
          }

          uint8_t bufferStep = 0;
          for (int j = 0; j <= (length/2)-1; j++) {
            for (int k = 0; k <= 3; k++) {
              seqs[j][k + 4 * (activePtrn - 1)] &= ~(0b00000001 << activeBank);
              seqs[j][k + 4 * (activePtrn - 1)] |= (bool(freezeBuffer[bufferStep] & (0b00000001 << k)) << activeBank);
            }
            bufferStep++;
            if (bufferStep >= breakLength) {
              bufferStep = 0;
            }
          }

          activeSubmode = 0;
          breakFreeze = 0b00000000;
          resetNow();
          toFlash[3+activePtrn] = true;
        }
    }
  }
  else {
    updateFillOrder();

    for (int i = 0; i <= 3; i++) {
      if (doubleTappedTrig[i]) {
        breakFreeze = i+1;
        doubleTappedTrig[i] = false;
        }
      }
  }
  
  if (breakLEDon || !(buttons[buttonTrig1step][buttonTrig1group] || buttons[buttonTrig2step][buttonTrig2group] || buttons[buttonTrig3step][buttonTrig3group] || buttons[buttonTrig4step][buttonTrig4group])){
    outs[faderLEDstep][faderLEDgroup] = HIGH;
  }
  
  if (altModes[0][0] && (buttons[buttonTrig1step][buttonTrig1group] || buttons[buttonTrig2step][buttonTrig2group] || buttons[buttonTrig3step][buttonTrig3group] || buttons[buttonTrig4step][buttonTrig4group])) {
        outs[breakOutstep][breakOutgroup] = HIGH;
  }

  if (!buttons[buttonTrig1step][buttonTrig1group] && !buttons[buttonTrig2step][buttonTrig2group] && !buttons[buttonTrig3step][buttonTrig3group] && !buttons[buttonTrig4step][buttonTrig4group]){
    outs[faderLEDstep][faderLEDgroup] = HIGH;
  }
  stripStepMeter();
}

void shredMode() {
  
  ptrnUpdate();
  ptrnLEDsUpdate();
  
  if (!altModes[1][0]) {

    // Handle LEDs and Fader
    outs[faderLEDstep][faderLEDgroup] = HIGH;
    uint8_t shredIndex = map(faderValue-1, 0, 1023, 9, -1);
    bool shredSeq[8];
      for (int i = 0; i <= 7; i++){
        shredSeq[i] = shredSeqs[shredIndex] & (1 << (7-i));
        outs[stripLEDsstep[i]][stripLEDsgroup[i]] = shredSeq[i];
      }
      // Detect shredTracks[0], if it exists, tempMute all else
      if (!shredTracks[0])
      {
        for (int i = 0; i <= 3; i++)
        {
          if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
          {
            shredTracks[0] = i + 1;
          }
          // tempMute[i] = false;
        }
      }
        // if shredTracks[0] exists, tempMute everything else and detect shredTracks[1]
        else
        { 
          for (int i = 0; i <= 3; i++)
          {
            tempMute[i] = (i != (shredTracks[0] - 1));
            if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
            {
              for (int j = 0; j <= 3; j++)
              {
                tempMute[j] = false;
              }
              shredTracks[1] = i + 1;

              // Shred the two tracks
              // shredTracks[0] - LEFT side of fader, shredTracks[1] - RIGHT side of fader
              int k = 0;
              for (int j = 0; j <= (maxLength / 2 - 1); j++)
              {
                toShred[0] = seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] & (1 << activeBank);
                toShred[1] = seqs[j][shredTracks[1] - 1 + 4 * (activePtrn - 1)] & (1 << activeBank);

                seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] = (seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] & ~(1 << activeBank)) | (((toShred[0] || toShred[1]) && !shredSeq[k]) << activeBank);
                seqs[j][shredTracks[1] - 1 + 4 * (activePtrn - 1)] = (seqs[j][shredTracks[1] - 1 + 4 * (activePtrn - 1)] & ~(1 << activeBank)) | (((toShred[0] || toShred[1]) &&  shredSeq[k]) << activeBank);

                if (k < 7)
                {
                  k++;
                }
                else
                {
                  k = 0;
                }
              }

              toFlash[shredTracks[0] - 1] = true;
              toFlash[shredTracks[1] - 1] = true;
              shredTracks[0] = 0;
              shredTracks[1] = 0;
              break;
            }
          }
        }

    // handle Double Taps
    for (int i = 0; i <= 3; i++) {
      if (doubleTappedTrig[i]) {
        toFlash[i] = true;
        shredTracks[0] = i + 1;

        // Shred the double tapped track against the other three
        // shredTracks[0] - LEFT side of fader, shredTracks[1] - RIGHT side of fader
        int k = 0;
        for (int j = 0; j <= (maxLength / 2 - 1); j++)
        {

          toShred[0] = seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] & (1 << activeBank);
          toShred[1] = false;
          for (int l = 0; l <= 3; l++)
          {
            if (l != i)
            {
              toShred[1] = toShred[1] || seqs[j][l + 4 * (activePtrn - 1)] & (1 << activeBank); // detect if any of the remaining sequences have some trigger in the j-th step
            }
          }

          if (toShred[0] || toShred[1]) {
            if (!shredSeq[k]) { // The double tapped track is dominant - only allow a trigger on that track
              seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] = (seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] & ~(1 << activeBank)) | (1 << activeBank);
              for (int l = 0; l <= 3; l++)
              {
                if (l != i)
                {
                  seqs[j][l + 4 * (activePtrn - 1)] = (seqs[j][l + 4 * (activePtrn - 1)] & (1 << activeBank)) & ~(1 << activeBank);
                }
              }
            }
            else { // The remaining three tracks are dominant, remove any trigger from track 1, leave the other 3 tracks without change
              seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] = (seqs[j][shredTracks[0] - 1 + 4 * (activePtrn - 1)] & (1 << activeBank)) & ~(1 << activeBank);
            }
          }
          if (k < 7)
          {
            k++;
          }
          else
          {
            k = 0;
          }
      }
          shredTracks[0] = 0;
    }
    }    

    // When Nothing is held, refresh Shred Ptrns
    if (!buttons[buttonTrigstep[0]][buttonTriggroup[0]] && !buttons[buttonTrigstep[1]][buttonTriggroup[1]] && !buttons[buttonTrigstep[2]][buttonTriggroup[2]] && !buttons[buttonTrigstep[3]][buttonTriggroup[3]]) {
      shredTracks[0] = 0;
      shredTracks[1] = 0;
      for (int j = 0; j <= 3; j++)
      {
        tempMute[j] = false;
      }
    }
  }
  else {

    clearLEDstrip();
    outs[faderLEDstep][faderLEDgroup] = true;

  if (modeChanged) {
    // modeChanged = false;

    flashTimer = currentTime;
    prevFlashState = HIGH;
    prevFader = faderValue;
    readFader = false;
  }

  if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
    readFader = true;
  }

  uint8_t stepsToShred = 7+4;
  if (readFader) {
    stepsToShred = 0;
    for (int i = 0; i <= 15; i++) {
      if (faderValue < ((i+1) * (1024 / 16))) {
        stepsToShred++;
      }
    }
  }

  for (int i = 0; i <= 7; i++)
  {
    if (stepsToShred > 8)
    {
      if (stepsToShred - 9 >= i)
      {
        outs[stripLEDsstep[i]][stripLEDsgroup[i]] = true;
      }
    }
      else
      {
        if (stepsToShred <= (8 - i))
        {
          outs[stripLEDsstep[7 - i]][stripLEDsgroup[7 - i]] = true;
        }
      }
  }


  if (bufferSequence){ // Save sequence into buffer on entering Shredmode, or changing patterns
    for (int i = 0; i <= (maxLength / 2 - 1); i++)
    {
      seqBuffer[i] = 0b00000000;
      for (int j = 0; j <= 3; j++)
      {
        seqBuffer[i] |= ((((seqs[i][4 * (activePtrn - 1) + j] & (1 << activeBank))) >> activeBank) << j);
      }
        }
        bufferSequence = false;
  }
  
  for (int i = 0; i <= 3 ; i++) { // i-th trigger button pressed
    if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) {
      int firstStep = (length/8)*i; // First step to copy from
      int firstPasteStep = ((step-2) / 2) + 1;
        if (firstPasteStep == (length / 2)) {
          firstPasteStep = 0;
        }

        if (step & 1) {
        bool bufferedTrigs[4] = {(seqBuffer[firstStep] & (1 << 0)), (seqBuffer[firstStep] & (1 << 1)), (seqBuffer[firstStep] & (1 << 2)), (seqBuffer[firstStep] & (1 << 3))};
        for (int j = 0; j <= 3; j++) {
          if (bufferedTrigs[j]) {
            trig(j+1);
          }
        }
        }

        for (int j = 0; j <= 7; j++)
        {
          for (int k = 0; k <= 3; k++)
          {
            if (stepsToShred <= 8 && j >= stepsToShred) {
              seqs[firstPasteStep + j][4*(activePtrn - 1) + k ] = (seqs[firstPasteStep + j][4*(activePtrn - 1) + k ] & ~(1 << activeBank));
            }
            else {
              seqs[firstPasteStep + j][4*(activePtrn - 1) + k ] = (seqs[firstPasteStep + j][4*(activePtrn - 1) + k ] & ~(1 << activeBank)) | (((seqBuffer[firstStep + j] & (1 << k)) >> k) << activeBank); // Paste a chunk of the buffered sequence into pattern memory
            }
          }

          if ((firstPasteStep + j) == (length / 2) || (stepsToShred > 8 && (j == (stepsToShred - 9))))
          { // Stop pasting if end of pattern reached OR if stepsToShred has been reached (Right side of fader)
            break;
          }
      }
    }
  }
  bar = seqStep / stepsPerLED;

  outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
  if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}}
}

void probabilityMode() {
  ptrnUpdate();
  ptrnLEDsUpdate();
  trigLights = false;
  clearLEDstrip();
  outs[faderLEDstep][faderLEDgroup] = HIGH;

    if (modeChanged || prevButtons[buttonOptionsstep][buttonOptionsgroup]) {
      prevFader = faderValue;
      readFader = false;
      // modeChanged = false;
    }

    if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
      readFader = true;
    }

  if (readFader){
    probability = 1023 - faderValue;
  }
    // for (int i = 0; i <= 7; i++) {
      if (probability < ((1023/2)-(faderDeadzone/2))) {
        for (int j = 0; j <= 3; j++)
        {
          if (probability <= ((j + 1) * (1023 / 8))) {
          outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
          }
        }
      }
      else if (probability > ((1023/2)+(faderDeadzone/2))) {
        for (int j = 4; j <= 7; j++)
        {
          if (probability >= (j * (1023 / 8))) {
            outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
          }
        }
      }
    // } 

  bar = seqStep / stepsPerLED;

  outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
  if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}

  for (int i = 0; i <= 3; i++) {
    if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] > prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) { probabilityActive[i] = !probabilityActive[i]; }
    outs[trigLEDSstep[i]][trigLEDSgroup[i]] = probabilityActive[i];
  }

  // Handle probability mode switching - double tap to cycle through modes per channel
  for (int i = 0; i <= 3; i++) {
    if (doubleTappedTrig[i]) {
      uint8_t channelState = (microtimingProbability >> 2*i) & 0b11;
      channelState = ((channelState + 1) & 0b11);
      if (channelState == 0) {
        channelState = 1;
      }
      microtimingProbability = (microtimingProbability & ~(0b11 << (2 * i)));
      microtimingProbability = (microtimingProbability |  (channelState << (2 * i)));
      microtimingProbabilityChanged = 0b11 << (2*i);
      flashTimer = currentTime;
      flashStarted = currentTime;
      prevFlashState = HIGH;
    }
  }
  if (microtimingProbabilityChanged) {
    clearLEDstrip();
    if (currentTime - flashTimer > (flashLength/2)) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
    if ((currentTime - flashStarted) > flashFor) {microtimingProbabilityChanged = 0b00000000;}
    for (int i = 0; i <= 7; i++) {
        if (((microtimingProbabilityChanged & (1 << i)) & (microtimingProbability)) && ((currentTime - flashStarted) < flashFor/3)) {
          outs[stripLEDsstep[i]][stripLEDsgroup[i]] = prevFlashState;
        }
        else {
        outs[stripLEDsstep[i]][stripLEDsgroup[i]] = microtimingProbability & (1 << i) ; }
    }
  }
}

void xFadeMode() {
  muteMode();
  outs[faderLEDstep][faderLEDgroup] = true;
  clearPtrnLEDs();
  clearLEDstrip();

  if (modeChanged) {
    // modeChanged = false;
    
    if (altModes[3][0] && (chainLength > 1)) {
      xFadePtrns[0] = activeBank+1;
      xFadePtrns[1] = 0;
      for (int i = 0; i <= 7; i++) {
        bankChain[i] = activeBank;
      }
    }
    else {
    xFadePtrns[0] = activePtrn;
    xFadePtrns[1] = 0;
    chainLength = 1;
    patternChain[0] = activePtrn;
    }

    flashTimer = currentTime;
    prevFlashState = HIGH;
    prevFader = faderValue;
    readFader = false;

      if (length > 32) {
        xFadeStep = 32;
      }
      else {
        xFadeStep = 16;
      }
  }

  if (buttons[buttonOptionsstep][buttonOptionsgroup] < prevButtons[buttonOptionsstep][buttonOptionsgroup]) {
    readFader = false;
    prevFader = faderValue;
  }
      
  for (int i = 0; i <= 3; i++) {    
      if ((buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) && ((i+1) != (xFadePtrns[0]))) {
              xFadePtrns[1] = i+1;
            }
      }

  if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
      readFader = true;
  }

    if (length > 32) {
        if (readFader && !buttons[buttonOptionsstep][buttonOptionsgroup]){
        xFadeStep = 32-map(faderValue-1, 0, 1023, 32, -1);
        }
        for (int i = 0; i <= 7; i++) {
          outs[stripLEDsstep[i]][stripLEDsgroup[i]] = (32 - xFadeStep > (i * (32 / 8)));
        }
      }
      else {
        if (readFader && !buttons[buttonOptionsstep][buttonOptionsgroup]){
        xFadeStep = 16-map(faderValue-1, 0, 1023, 16, -1);
        }
        for (int i = 0; i <= 7; i++) {
          outs[stripLEDsstep[i]][stripLEDsgroup[i]] = (16 - xFadeStep > (i * (16 / 8)));
        }
  }

  if (xFadePtrns[1])
  {
      clearPtrnLEDs();
      if (currentTime - flashTimer > flashLength)
      {
        prevFlashState = !prevFlashState;
        flashTimer = currentTime;}
      outs[ptrnLEDSstep[xFadePtrns[0]-1]][ptrnLEDSgroup[xFadePtrns[0]-1]] = prevFlashState;
      outs[ptrnLEDSstep[xFadePtrns[1]-1]][ptrnLEDSgroup[xFadePtrns[1]-1]] = prevFlashState;
    if (altModes[3][0] && (chainLength > 1)) {
      outs[ptrnLEDSstep[activeBank]][ptrnLEDSgroup[activeBank]] = HIGH;
    }
    else {
      outs[ptrnLEDSstep[activePtrn-1]][ptrnLEDSgroup[activePtrn-1]] = HIGH;
    }
      bar = seqStep / stepsPerLED;
      outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
  
      for (int i = 0; i <= 3; i++) {
        if (doubleTappedTrig[i]) { // When i-th trigger button is double-tapped
          toFlash[i] = true;
          toFlash[i+4] = true;
          // Write a snapshot of the current playback into the i-th pattern
          for (int j = 0; j <= (length / 2) - 1; j++)
          {
              uint8_t patternIndex = xFadePtrns[(xFadeStep) <= (j & 31)]-1;
              for (int k = 0; k <= 3; k++)
              {
                uint8_t note_buffer = seqs[j][4 * patternIndex + k];
                seqs[j][4 * i + k] &= ~(0b1 << activeBank);
                seqs[j][4 * i + k] |= (note_buffer & (1 << activeBank));
              }
          }
    
          // Quit the x-fade mode and activate the i-th pattern
          activePtrn = i+1;
          chainLength = 1;
          patternChain[0] = activePtrn;
          bankChain[0] = activeBank;
          activeSubmode = 0;
         }

      }

  }
  else {
    stripStepMeter();
    if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
    for (int i = 0; i <= 3; i++) {
      outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = prevFlashState;
    }
    outs[ptrnLEDSstep[xFadePtrns[0]-1]][ptrnLEDSgroup[xFadePtrns[0]-1]] = HIGH;
  }

}


void updateAssignSubmode() {
  for (int i = 0; i <= 3; i++){
    if (buttons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]] > prevButtons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]]) {
      assignSubmode[0] = RECmode;
      assignSubmode[1] = i+1;
    }
  }
}

void mux() {
  digitalWrite(ST_READ, LOW);
  digitalWrite(ST_READ, HIGH);

  for (int i = 0; i <= 7; i++)
  {
    buttons[i][0] = !digitalRead(In1);
    buttons[i][1] = !digitalRead(In2);

    digitalWrite(Out1, outs[i][0]);
    digitalWrite(Out2, outs[i][1]);
    digitalWrite(Out3, outs[i][2]);
    digitalWrite(Out4, outs[i][3]);

    digitalWrite(SR_CLOCK, HIGH);
    digitalWrite(SR_CLOCK, LOW);
    }
    digitalWrite(ST_WRITE, HIGH);
    digitalWrite(ST_WRITE, LOW);

    buttons[buttonRECstep][buttonRECgroup] = !digitalRead(buttonRECpin);
    buttons[resetInstep][resetIngroup] = !digitalRead(resetInPin);

    extClockPresent = !digitalRead(extClockDetection);
    extClockState = !digitalRead(clockIn);

    faderValue = analogRead(fader);
}

void handleModes() {
// RECmode detection
  RECmode = buttons[buttonRECstep][buttonRECgroup];

  // Execute when RECmode changes
  if (buttons[buttonRECstep][buttonRECgroup] != prevButtons[buttonRECstep][buttonRECgroup]) {
    if (!(bootOptions & (1 << 2))) {
      activeSubmode = 0;
    }
  }

  if (buttons[buttonAssignstep][buttonAssigngroup]) {  // Assign mode
      if (!prevButtons[buttonAssignstep][buttonAssigngroup]) {
        preAssignRECmode = RECmode;
        preAssignSubmode = activeSubmode;
      }
      updateAssignSubmode();
      RECmode = assignSubmode[0];
      activeSubmode = assignSubmode[1];
    }

    else if (!buttons[buttonOptionsstep][buttonOptionsgroup]) {
    submodeUpdate();
  };

  refreshStates();

  if (buttons[buttonOptionsstep][buttonOptionsgroup]) {
  handleOptions();
  }
  else if (buttons[buttonMutestep][buttonMutegroup]) {
    handleMutes();  
    stripStepMeter();
    ptrnLEDsUpdate();
  }
  else if (RECmode) {  // REC Mode
    submodeLEDsUpdate();
    trigLights = true;
    outs[faderLEDstep][faderLEDgroup] = LOW;

    switch (activeSubmode) {
      case 0:  // default REC submode
        trigRecord();
        break;
      case 1:  // CLEAR submode
        clearSeq();
        break;
      case 2:  // COPY submode
        copy();
        break;
      case 3:  // FILL submode
        fill();
        break;
      case 4:  // CHAIN submode
        chain();
        break;
    }
  }       // REC Mode End
  else {  // Live Mode
    submodeLEDsUpdate();
    trigLights = true;
    outs[faderLEDstep][faderLEDgroup] = LOW;

    switch (activeSubmode) {
      case 0: // Finger drumming submode
        fingerDrumming();
        break;
      case 1:  // BREAK submode
        breakMode();
        break;
      case 2: // Shred submode
        shredMode();
        break;
      case 3: // Probability submode
        probabilityMode();
        break;
      case 4: // X-Fade submode
        xFadeMode();
        break;
    }
  }  // Live Mode End

  // Reset Assign mode
  if (buttons[buttonAssignstep][buttonAssigngroup] < prevButtons[buttonAssignstep][buttonAssigngroup]) {
    RECmode = preAssignRECmode;
    activeSubmode = preAssignSubmode;
  }

  // REC Mode indication
  outs[RECLEDstep][RECLEDgroup] = buttons[buttonRECstep][buttonRECgroup];
}

void checkDoubleTap() {
for (int i = 0; i <= 3; i++)
    {
      if (doubleTappedTrig[i]) {
        doubleTappedTrig[i] = false;
      }
      else if (buttons[buttonTrigstep[i]][buttonTriggroup[i]] && !prevButtons[buttonTrigstep[i]][buttonTriggroup[i]])
      {
      prevTrigTap[i] = newTrigTap[i];
      newTrigTap[i] = currentTime;
      if (!doubleTappedWindow[i]) {
        doubleTappedWindow[i] = true;
      }
      else {
        doubleTappedTrig[i] = true;
      }
      }
    }
}

void handleClockIn() { 
  if (extClockPresent) {
    clockInState = extClockState;
      if (clockDiv == 1) { // When clockDiv == 1, step progression between clock ticks has to be estimated
            if (estimateClock && ((currentTime - prevClockTime) > estimatedTempo[bool(~step & 0b10)]) && (step & 0b00000001)) {
              progressClock = true;
              estimateClock = false;
            }
            if (clockInState && !lastClockState && !pause)
            {
              if (step & 0b00000001) {
                step++;
              }
              progressClock = true;
              estimatedTempo[bool(step & 0b10)] = (currentTime - prevClockTime) / 2; // two tempos are estimated in sequence to take 2-note swing into account
              prevClockTime = currentTime;
              estimateClock = true;
             }
        }
        else {
          if (clockInState && !lastClockState && !pause) {
            estimatedTempo[bool(step & 0b10)] = (currentTime - prevClockTime) / 2;
            prevClockTime = currentTime;
            estimateClock = true;
            if (clockInCounter == 1)
            {
              progressClock = true;

            }

            if (clockInCounter >= clockDiv/2) {
              clockInCounter = 1;
            }
            else {
              clockInCounter++;
            }
          }
        }
    }
  else {
    
    unsigned long tempoToUse = tempo;
    signed long swingToUse = tempo/2;
    swingToUse = (-long(tempo) / 2) + swingAmount * long(tempo) / 1023;
    if ((swingAmount < ((1023 / 2) - (faderDeadzone / 2))) || (swingAmount > ((1023 / 2) + (faderDeadzone / 2)))) {
      if ((step & 0b01) != ((step & 0b10) >> 1)) { // pickout steps 1-2, 5-6, 9-10...
        tempoToUse = tempo + swingToUse;
      }
      else {
        tempoToUse = tempo - swingToUse;
      }
    }
    
    if ((currentTime - stepStarted) > tempoToUse) {
      progressClock = true;
      stepStarted = micros();
      }
    }

  // if (clockInState && !lastClockState && !pause) {
  if (progressClock && !pause) {
    progressClock = false;
    newStep = HIGH;
    if (step < length) {

      step++;
      
    } else {

      step = 1;
      
      if (chainStep < (chainLength-1)){chainStep++;}
      else{chainStep = 0;}
      activePtrn = patternChain[chainStep];
      activeBank = bankChain[chainStep];
    }
    playSeq();
  }
  lastClockState = clockInState;
}

void handleClockOut() {

  if (extClockPresent) {
    if (!delayClock) {
    trigClockOut();
    }
    else {
      // Start delayed clock timer
      delayClock = false;
      delayedClockTimer = micros();
      delayingClock = true;
    }
    clockOutCounter = 1;
  }
  else {
    if (clockOutCounter == 1)
    {
      if (!delayClock) {
    trigClockOut();
    }
    else {
      // Start delayed clock timer
      delayClock = false;
      delayedClockTimer = micros();
      delayingClock = true;
    }
    }

    if (clockOutCounter >= clockDiv) {
      clockOutCounter = 1;
    }
    else {
      clockOutCounter++;
    }
  }
}

void handleDelayedClock() {

  if ((currentTime - delayedClockTimer) >= clockDelayTime) {
    trigClockOut();
    delayingClock = false;
  }
}

void handleDelayedTrigs()
{
  for (int i = 0; i <= 3; i++)
  {
    if (trigDelayTimer[i] > 0 && trigRepeatsToDo[i] > 0)
    {
      if (timePassed >= trigDelayTimer[i])
      {
        trig(i + 1);

        trigRepeatsToDo[i]--;
        if (trigRepeatsToDo[i] > 0)
        {
          trigDelayTimer[i] += trigDelays[i]-timePassed;
        }
        else {
          trigDelayTimer[i] = 0;
        }
      }
      else
      {
        trigDelayTimer[i] -= timePassed;
      }
    }
  }
}

void handleHeldReset() {
  if (buttons[buttonResetstep][buttonResetgroup]) { // cause a reset when pressing any of the trig buttons / pattern buttons when while RESET is held
    for (int i = 0; i <= 3; i++) {
      if((buttons[buttonTrigstep[i]][buttonTriggroup[i]]>prevButtons[buttonTrigstep[i]][buttonTriggroup[i]]) || (buttons[buttonPatternStep[i]][buttonPatternGroup[i]]>prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]])) {
        resetNow();
      }
    }
  }
}

void handleOptions() {
    clearPtrnLEDs();
    clearSubmodeLEDs();
    stripStepMeter();    
    outs[faderLEDstep][faderLEDgroup] = true;

    if (!prevButtons[buttonOptionsstep][buttonOptionsgroup]) { // if Options was just entered
      prevFader = faderValue;
      readFader = false;

      swingFader = false;
      if ((currentTime - prevOptionsTap) < doubleTap) {
        swingFader = true; // if FN was double-tapped, fader will set swing instead of tempo
      }
      prevOptionsTap = currentTime;
    }

    if ((abs(prevFader - faderValue) > 5) && (readFader == false)) {
      readFader = true;
    }

    if (readFader) {
      if (swingFader) {
        swingAmount = 1023-faderValue;
      }
      else {
        tempo = map(faderValue, 0, 1023, maxTempo[extendedTempo], minTempo[extendedTempo]);
      }
    }

    handleBanks();
    handleAltModes();

    if (buttons[buttonResetstep][buttonResetgroup] > prevButtons[buttonResetstep][buttonResetgroup]) {
      pause = !pause;
      clockInCounter = 1;

    if ((step & 0b00000001) && (step < length)) // don't start on even steps which have no notes
      {
        step++;
      }
      stepStarted = micros();
    }
    if (pause) {
      outs[stripLED2step][stripLED2group] = true;
    }

    if (buttons[buttonAssignstep][buttonAssigngroup] > prevButtons[buttonAssignstep][buttonAssigngroup]) {
      extendedTempo = !extendedTempo;
    }
    if (extendedTempo) {
      outs[stripLED4step][stripLED4group] = true;
      outs[stripLED5step][stripLED5group] = true;
    }

    if (swingFader) {
      clearLEDstrip();

      if (swingAmount < ((1023/2)-(faderDeadzone/2))) {
        for (int j = 0; j <= 3; j++)
        {
          if (swingAmount <= ((j + 1) * (1023 / 8))) {
          outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
          }
        }
      }
      else if (swingAmount > ((1023/2)+(faderDeadzone/2))) {
        for (int j = 4; j <= 7; j++)
        {
          if (swingAmount >= (j * (1023 / 8))) {
            outs[stripLEDsstep[j]][stripLEDsgroup[j]] = true;
          }
        }
      }
      
      outs[faderLEDstep][faderLEDgroup] = prevFlashState;
      if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
    }


    if (buttons[buttonTrig1step][buttonTrig1group] > prevButtons[buttonTrig1step][buttonTrig1group])
    {
      if (clockDiv == maxClockDiv)
      {
        clockDiv = 1;
      }
      else
      {
        clockDiv = 2 * clockDiv;
      }

      step = 0;
      chainStep = 0;
      activePtrn = patternChain[chainStep];
      activeBank = bankChain[chainStep];
      resetOnNextStep = true;
      flashTimer = currentTime;
      flashStarted = currentTime;
      prevFlashState = HIGH;
      resetNow();

      switch (clockDiv) {
        case 1:
          settingToFlash = 0b11111111;
          break;
        case 2:
          settingToFlash = 0b10101010;
          break;
        case 4:
          settingToFlash = 0b10001000;
          break;
        case 8:
          settingToFlash = 0b10000000;
          break;
      }

      }

    if (buttons[buttonTrig2step][buttonTrig2group] > prevButtons[buttonTrig2step][buttonTrig2group]) {
      if (length == 128) {
        length = 32;
      }
      else {
        length = 2 * length;
      }
      stepsPerLED = (length / 2) / 8;
      step = 0;
      chainStep = 0;
      activePtrn = patternChain[chainStep];
      activeBank = bankChain[chainStep];
      resetOnNextStep = true;
      flashTimer = currentTime;
      flashStarted = currentTime;
      prevFlashState = HIGH;
      resetNow();

      switch (length) {
        case 32:
          settingToFlash = 0b11000000;
          break;
        case 64:
          settingToFlash = 0b11110000;
          break;
        case 128:
          settingToFlash = 0b11111111;
          break;
      }
    }

    if (settingToFlash) {
      clearLEDstrip();
      if (currentTime - flashTimer > (flashLength/2)) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
      if ((currentTime - flashStarted) > flashFor) {settingToFlash = 0b00000000;}
      for (int i = 0; i <= 7; i++) {
        outs[stripLEDsstep[i]][stripLEDsgroup[i]] = !prevFlashState && (settingToFlash & (1 << (7 - i))); 
      }
    }

    if (buttons[buttonTrig3step][buttonTrig3group] > prevButtons[buttonTrig3step][buttonTrig3group]) {
      newTap = currentTime;
      readFader = false;
      if (prevTap != 0) {
        tempo = (newTap - prevTap)/4;
        if (tempo > minTempo[extendedTempo]) {
          tempo = minTempo[extendedTempo];
        }
        else if (tempo < maxTempo[extendedTempo]) {
          tempo = maxTempo[extendedTempo];
        }
      }
      prevFader = analogRead(fader);
      prevTap = newTap;
    }

    if (buttons[buttonTrig4step][buttonTrig4group] > prevButtons[buttonTrig4step][buttonTrig4group]) {
      if (buttons[buttonResetstep][buttonResetgroup]) {
      load();
      // resetMCU();
      // printSeqs();
      }
      else {
      save();
      }
    }

    bar = seqStep / stepsPerLED;
    if (!settingToFlash) {
      outs[stripLEDsstep[bar]][stripLEDsgroup[bar]] = prevFlashState;
      if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
    }
  }

void handleBanks() {
    for (int i = 0; i <= 3; i++) {
          if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) {
            if (!(bootOptions & (1 << 3))) {
                activeBank = i;
                bufferSequence = true;
              }
            for (int j = 0; j <= 7; j++)  {
              bankChain[j] = i;
            if (altModes[3][0] && (chainLength > 1)) { // treat a special case when xFading banks but user switches bank manually - refresh the xFade mode
              xFadePtrns[0] = activeBank+1;
              modeChanged = true;
              xFadePtrns[1] = 0;
            }
          }
        }
        outs[ptrnLEDSstep[activeBank]][ptrnLEDSgroup[activeBank]] = true;

          if (chainStep < (chainLength-1)) {
            nextBank = bankChain[chainStep+1];
            }
          else {
            nextBank = bankChain[0];
            }

          if (activeBank != nextBank){
            for (int j = 0; j <= 3; j++) {
              if (nextBank == (j+0)) {outs[ptrnLEDSstep[j]][ptrnLEDSgroup[j]] = prevFlashState;}
            }
            if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
        }
    }
}

void handleAltModes() {
  for (int i = 0; i <= 3; i++) {
    if (buttons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]] > prevButtons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]]) {
      altModes[i][RECmode] = !altModes[i][RECmode];
    }
    outs[submodeLEDSstep[i]][submodeLEDSgroup[i]] = altModes[i][RECmode];
  }
  if (buttons[buttonMutestep][buttonMutegroup] > prevButtons[buttonMutestep][buttonMutegroup]) {
    altModes[4][RECmode] = !altModes[4][RECmode];
    altModes[4][!RECmode] = altModes[4][RECmode];
  }
  if (altModes[4][RECmode]) {
    outs[stripLED7step][stripLED7group] = true;
  }

  // DISABLE REDUNDANT ALT MODE INDICATION HERE (force LEDs to stay low for unused alt modes)
}

void handleMutes() {
    trigLights = false;
    muteMode();
    if (!prevButtons[buttonMutestep][buttonMutegroup]) {
      prevMuteTap = newMuteTap;
      newMuteTap = currentTime;
      if (doubleTappedMute) {
        if (mute[0] && mute[1] && mute[2] && mute[3]) {
          mute[0] = false; mute[1] = false; mute[2] = false; mute[3] = false;
        }
        else {
          mute[0] = true; mute[1] = true; mute[2] = true; mute[3] = true;
        }
        doubleTappedMute = false;
      }
      doubleTappedMute = true;
    }
}

void takeDownOuts() {
  // Take down Trigger outs and LEDs
  for (int i = 0; i <= 3; i++) {
    if (trigON[i]) {
      if ((currentTime - trigStarted[i]) > triggerLength) {
        outs[trigOutsStep[i]][trigOutsGroup[i]] = LOW;
        trigON[i] = false;
      }
    }
    if (trigLights && (outs[trigLEDSstep[i]][trigLEDSgroup[i]] == !(mute[i] || tempMute[i]))) {
      if ((currentTime - trigStarted[i]) > trigLEDlength) {
        // outs[trigLEDSstep[i]][trigLEDSgroup[i]] = LOW;
        outs[trigLEDSstep[i]][trigLEDSgroup[i]] = mute[i] || tempMute[i];
      }
    }
  }

  // Take down Clock out
      if ((currentTime - clockOutStarted) > triggerLength) {
        outs[clockOutstep][clockOutgroup] = LOW;
        clockOutOn = false;
      }
      if ((currentTime - clockOutStarted) > clockFlashLength) {
        outs[clockLEDstep][clockLEDgroup] = LOW;
        clockOutOn = false;
      }

  // Take down Reset out
      if (((currentTime - resetStarted) > triggerLength) && ((!altModes[0][0] && !breakOn) || (bootOptions & (1 << 0)))) {
        outs[resetOutstep][resetOutgroup] = LOW;
        resetOn = false;
      }

  // Take down Break out
      if ((currentTime - breakStarted) > triggerLength) {
        if (!altModes[0][0]) {
        outs[breakOutstep][breakOutgroup] = LOW;
        }
        else if (!(bootOptions & (1 << 0))) {
        outs[resetOutstep][resetOutgroup] = LOW; 
        }
        breakOn = false;
      }

      if (altModes[0][0] && (modeChanged || ((breakFreeze == 0) && (!buttons[buttonTrig1step][buttonTrig1group] && !buttons[buttonTrig2step][buttonTrig2group] && !buttons[buttonTrig3step][buttonTrig3group] && !buttons[buttonTrig4step][buttonTrig4group])))) {
        outs[breakOutstep][breakOutgroup] = LOW;
      }

      if (breakLEDon && ((currentTime - breakStarted) > trigLEDlength)) {
        outs[faderLEDstep][faderLEDgroup] = LOW;
        breakLEDon = false;
      }

  // Take down Fader LED when flashing in Fill mode
  if (fillLEDon) {
    if ((currentTime - fillStarted) > trigLEDlength) {
      outs[faderLEDstep][faderLEDgroup] = LOW;
      fillLEDon = false;
    }
  }
}

void refreshStates() {
  modeChanged = false;
  if ((prevRECmode != RECmode) || (prevSubmode != activeSubmode)) {

  // Refresh copy mode if submode changed
  // if (!RECmode || (activeSubmode != 2)) {
    copying = false;
    pasting = false;
  // }


  // Refresh chain recording mode if submode changed
  // if (!RECmode || (activeSubmode != 4)) {
  // justEnteredChain = true;
  // }

  // Refresh Break mode if submode changed
  // if (RECmode || (activeSubmode != 1)) {

  // }

  // Refresh Probability mode if submode changed
  // if (RECmode || (activeSubmode != 3)) {
  // justEnteredProbability = true;
  // }

  // Refresh X-Fade mode if submode changed
  // if (RECmode || (activeSubmode != 4)) {
  // justEnteredXFade = true;
  // }

  jumpTo = 0;
  jumpBy = 0;

  modeChanged = true;

  // Refresh momentary mutes when not in modes that utilize them
  // if (!((!RECmode && (activeSubmode == 0)) || (RECmode && (activeSubmode == 0)) || (altModes[0][1] && RECmode && (activeSubmode == 1)) || (!altModes[2][1] && RECmode && (activeSubmode == 3)) || (!altModes[1][0] && !RECmode && (activeSubmode == 2)))) {
    for (int i = 0; i <= 3; i++) {
      tempMute[i] = false;
      fillOrder[i] = false;
    }
  // }

  }
  
  // Refresh Shred mode if submode changed or activePtrn changed;
  if ((prevRECmode != RECmode) || (prevSubmode != activeSubmode) || (prevPtrn != activePtrn)) {
    bufferSequence = true;
    shredTracks[0] = 0;
    shredTracks[1] = 0;
  }

  // Refresh Options when out of the options mode
  if (!buttons[buttonOptionsstep][buttonOptionsgroup]) {
    prevTap = 0;
    settingToFlash = 0b00000000;
  }

  // Refresh Mute Double Tap
  if ((currentTime - newMuteTap) > doubleTap) {
    doubleTappedMute = false;
  }

  // Refresh Trig Double Tap
  for (int i = 0; i <= 3; i++) {
    if ((currentTime - newTrigTap[i]) > doubleTap)
    {
      doubleTappedWindow[i] = false;
    }
  }
  
  prevSubmode = activeSubmode;
  prevRECmode = RECmode;
}


void handleRepeatedFlashTimer() {
  for (int i = 0; i <= 7; i++) {
    if (prevToFlash[i] < toFlash[i]) {
      flashing[i] = true;
      repeatedFlashTimer = currentTime;
      repeatedFlashStarted = currentTime;
      prevRepeatedFlashState = HIGH;
    }
    prevToFlash[i] = toFlash[i];
    toFlash[i] = false;

    if (flashing[i]) { // i = 0:3 triggers, i = 4:7 pattern LEDs
    if (currentTime - repeatedFlashTimer > (flashLength/2)) {prevRepeatedFlashState = !prevRepeatedFlashState; repeatedFlashTimer = currentTime;}
          if ((currentTime - repeatedFlashStarted) > flashFor/3) {flashing[i] = false;}
           if (i < 4) {
          outs[trigLEDSstep[i]][trigLEDSgroup[i]] = !prevRepeatedFlashState;
          trigLights = false;
           }
          else {
          outs[ptrnLEDSstep[i-4]][ptrnLEDSgroup[i-4]] = !prevRepeatedFlashState; 
          }
      for (int j = 0; j <= 3; j++) {
        // if (j < 4) {
          outs[trigLEDSstep[j]][trigLEDSgroup[j]] = outs[trigLEDSstep[j]][trigLEDSgroup[j]] && flashing[j];
          //  }
        //   else {
        //   outs[ptrnLEDSstep[j-4]][ptrnLEDSgroup[j-4]] = outs[ptrnLEDSstep[j-4]][ptrnLEDSgroup[j-4]] && flashing[j];
        // }
      }
    }
  }
}

void save(){
  EEPROM.write(0, activePtrn);

  for (int i = 0; i <= 7; i++) { // Memory 1 to 8
    EEPROM.write(1 + i, patternChain[i]);
  }
  EEPROM.write(9, chainLength);

  EEPROM.write(10, clockDiv);
  EEPROM.write(11, length);
  EEPROM.write(12, assignSubmode[0]);
  EEPROM.write(13, assignSubmode[1]);

  EEPROM.write(14, (bool2bits(mute[0], mute[1], mute[2], mute[3])));

  EEPROM.write(15, (bool2bits(probabilityActive[0], probabilityActive[1], probabilityActive[2], probabilityActive[3])));
  EEPROM.put(16, probability);

  EEPROM.write(18, (tempo >> (8 * 0)) & 0xff);
  EEPROM.write(19, (tempo >> (8 * 1)) & 0xff);
  EEPROM.write(20, (tempo >> (8 * 2)) & 0xff);
  EEPROM.write(21, (tempo >> (8 * 3)) & 0xff);

  EEPROM.write(22, activeBank);

  EEPROM.write(23, bool2bits(altModes[0][0], altModes[1][0], altModes[2][0], altModes[3][0], altModes[4][0]));
  EEPROM.write(24, bool2bits(altModes[0][1], altModes[1][1], altModes[2][1], altModes[3][1], altModes[4][1]));

  EEPROM.write(25, pause);
  EEPROM.write(26, extendedTempo);

  EEPROM.write(27, bootOptions);

  for (int i = 0; i <= 7; i++) { // Memory 31 to 38
    EEPROM.write(31 + i, bankChain[i]);
  }

  EEPROM.write(39, microtimingProbability);
  EEPROM.put(40, swingAmount);

  for (int i = 0; i <= 3; i++) { // i-th track
    for (int j = 0; j <= 63; j++) { // j-th step
      byteToWrite = (seqs[j][i + 0]) | (seqs[j][i + 8] << 4);
      EEPROM.write(512 + j + 64 * i, byteToWrite);
      byteToWrite = (seqs[j][i + 4]) | (seqs[j][i + 12] << 4);
      EEPROM.write(512 + j + 64 * (i + 4), byteToWrite);
    }
  }
}

void load(){
  activePtrn = EEPROM.read(0);
  
  for (int i = 0; i <= 7; i++) { // Memory 1 to 8
    patternChain[i] = EEPROM.read(1 + i);
  }
  chainLength = EEPROM.read(9);

  clockDiv = EEPROM.read(10);
  length = EEPROM.read(11); stepsPerLED = (length / 2) / 8;
  assignSubmode[0] = EEPROM.read(12);
  assignSubmode[1] = EEPROM.read(13);

  memoryByte = EEPROM.read(14);
  for (int i = 0; i <= 3; i++) { // 
    mute[i] = bits2bool(memoryByte, i);
  }

  memoryByte = EEPROM.read(15);
  for (int i = 0; i <= 3; i++) { // 
    probabilityActive[i] = bits2bool(memoryByte, i);
  }

  probability = EEPROM.get(16,probability);

  tempo = 0;
  tempo |= (unsigned long) EEPROM.read(18) <<  0;
  tempo |= (unsigned long) EEPROM.read(19) <<  8;
  tempo |= (unsigned long) EEPROM.read(20) << 16;
  tempo |= (unsigned long) EEPROM.read(21) << 24;

  activeBank = EEPROM.read(22);

  memoryByte = EEPROM.read(23);
  for (int i = 0; i <= 4; i++) {
    altModes[i][0] = bits2bool(memoryByte, i);
  }
  memoryByte = EEPROM.read(24);
  for (int i = 0; i <= 4; i++) {
    altModes[i][1] = bits2bool(memoryByte, i);
  }

  pause = EEPROM.read(25);
  extendedTempo = EEPROM.read(26);

  bootOptions = EEPROM.read(27);

  for (int i = 0; i <= 7; i++) { // Memory 31 to 38
    bankChain[i] = EEPROM.read(31 + i);
  }

  microtimingProbability = EEPROM.read(39);
  swingAmount = EEPROM.get(40, swingAmount);

  for (int i = 0; i <= 3; i++)
  {
    for (int j = 0; j <= 63; j++)
    {
      memoryByte = EEPROM.read(512 + j + 64 * i);
      seqs[j][i + 0] = memoryByte & 0x0F; // 0x0F = 00001111
      seqs[j][i + 8] = (memoryByte >> 4) & 0x0F;
      memoryByte = EEPROM.read(512 + j + 64 * (i + 4));
      seqs[j][i + 4] = memoryByte & 0x0F;
      seqs[j][i + 12] = (memoryByte >> 4) & 0x0F;
    }
    }
}

byte bool2bits(bool bit0, bool bit1, bool bit2, bool bit3, bool bit4, bool bit5, bool bit6, bool bit7){ // compresses boolean values into the bits of a byte
  return ((bit0 << 0) | (bit1 << 1) | (bit2 << 2) | (bit3 << 3 | bit4 << 4) | (bit5 << 5) | (bit6 << 6) | (bit7 << 7));
}

bool bits2bool(byte byteBlock, int address) { // returns bool from byteBlock at address (0-3)
  return (byteBlock >> address) & 1;
}

void resetMCU() { asm volatile ("jmp 0"); }

void printSeqs() { // dump seqs into serial, can be used to edit seqs defintion
  for (int i = 0; i <= ((maxLength / 2) -1); i++) {
    Serial.print(F("{ "));
    for (int j = 0; j <= 15; j++) {
      uint8_t word = seqs[i][j];
      Serial.print(F("0b"));
      for (int k = 0; k <= 7; k++) {
        bool toPrint = word & (1 << (7 - k));
        Serial.print(toPrint);
      }
      if (j < 15) {
      Serial.print(F(","));
      }
      Serial.print(F(" "));
    }
    Serial.print(F("}"));
    if (i < ((maxLength / 2) -1)) {
    Serial.print(F(","));
    }
    
    Serial.println();
  }
  Serial.println(F("Done"));
}

void bootMenu() {
        outs[stripLEDsstep[0]][stripLEDsgroup[0]] = true; // show version number
        outs[stripLEDsstep[1]][stripLEDsgroup[1]] = true;
        outs[stripLEDsstep[2]][stripLEDsgroup[2]] = true;
        outs[stripLEDsstep[3]][stripLEDsgroup[3]] = true;
        outs[stripLEDsstep[4]][stripLEDsgroup[4]] = true;
        outs[stripLEDsstep[5]][stripLEDsgroup[5]] = true;
        outs[stripLEDsstep[6]][stripLEDsgroup[6]] = false;
        outs[stripLEDsstep[7]][stripLEDsgroup[7]] = true;
        // History:
        // V1.1 - 11111101
        // V1.0 - 11111110
        

        currentTime = micros();
        if (currentTime - flashTimer > flashLength) {prevFlashState = !prevFlashState; flashTimer = currentTime;}
        outs[clockLEDstep][clockLEDgroup] = prevFlashState;

        for (int i = 0; i <= 3; i++) {
          if (buttons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]] > prevButtons[buttonSubmodeStep[i]][buttonSubmodeGroup[i]]) {
            bootOptions ^= (1 << i);  // Toggle bit i
          }
          outs[submodeLEDSstep[i]][submodeLEDSgroup[i]] = (bootOptions & (1 << i)) != 0;

          if (buttons[buttonPatternStep[i]][buttonPatternGroup[i]] > prevButtons[buttonPatternStep[i]][buttonPatternGroup[i]]) {
            bootOptions &= 0b11001111;
            bootOptions |= (uint8_t(i)) << 4;
          }

          outs[ptrnLEDSstep[i]][ptrnLEDSgroup[i]] = (i == ((bootOptions & 0b00110000) >> 4));
        }


        // Record previous button state
        for (int i = 0; i <= 8; i++)
        {
          for (int j = 0; j <= 1; j++)
          {
            prevButtons[i][j] = buttons[i][j];
          }
        }
        mux();
}
