#pragma once


// From glfw3.h
namespace Normal {

#define NR_KEY_SPACE              (NRuint)32
#define NR_KEY_APOSTROPHE         (NRuint)39  /* ' */
#define NR_KEY_COMMA              (NRuint)44  /* , */
#define NR_KEY_MINUS              (NRuint)45  /* - */
#define NR_KEY_PERIOD             (NRuint)46  /* . */
#define NR_KEY_SLASH              (NRuint)47  /* / */
#define NR_KEY_0                  (NRuint)48
#define NR_KEY_1                  (NRuint)49
#define NR_KEY_2                  (NRuint)50
#define NR_KEY_3                  (NRuint)51
#define NR_KEY_4                  (NRuint)52
#define NR_KEY_5                  (NRuint)53
#define NR_KEY_6                  (NRuint)54
#define NR_KEY_7                  (NRuint)55
#define NR_KEY_8                  (NRuint)56
#define NR_KEY_9                  (NRuint)57
#define NR_KEY_SEMICOLON          (NRuint)59  /* ; */
#define NR_KEY_EQUAL              (NRuint)61  /* = */
#define NR_KEY_A                  (NRuint)65
#define NR_KEY_B                  (NRuint)66
#define NR_KEY_C                  (NRuint)67
#define NR_KEY_D                  (NRuint)68
#define NR_KEY_E                  (NRuint)69
#define NR_KEY_F                  (NRuint)70
#define NR_KEY_G                  (NRuint)71
#define NR_KEY_H                  (NRuint)72
#define NR_KEY_I                  (NRuint)73
#define NR_KEY_J                  (NRuint)74
#define NR_KEY_K                  (NRuint)75
#define NR_KEY_L                  (NRuint)76
#define NR_KEY_M                  (NRuint)77
#define NR_KEY_N                  (NRuint)78
#define NR_KEY_O                  (NRuint)79
#define NR_KEY_P                  (NRuint)80
#define NR_KEY_Q                  (NRuint)81
#define NR_KEY_R                  (NRuint)82
#define NR_KEY_S                  (NRuint)83
#define NR_KEY_T                  (NRuint)84
#define NR_KEY_U                  (NRuint)85
#define NR_KEY_V                  (NRuint)86
#define NR_KEY_W                  (NRuint)87
#define NR_KEY_X                  (NRuint)88
#define NR_KEY_Y                  (NRuint)89
#define NR_KEY_Z                  (NRuint)90
#define NR_KEY_LEFT_BRACKET       (NRuint)91  /* [ */
#define NR_KEY_BACKSLASH          (NRuint)92  /* \ */
#define NR_KEY_RIGHT_BRACKET      (NRuint)93  /* ] */
#define NR_KEY_GRAVE_ACCENT       (NRuint)96  /* ` */
#define NR_KEY_WORLD_1            (NRuint)161 /* non-US #1 */
#define NR_KEY_WORLD_2            (NRuint)162 /* non-US #2 */

	/* Function keys */
#define NR_KEY_ESCAPE             (NRuint)256
#define NR_KEY_ENTER              (NRuint)257
#define NR_KEY_TAB                (NRuint)258
#define NR_KEY_BACKSPACE          (NRuint)259
#define NR_KEY_INSERT             (NRuint)260
#define NR_KEY_DELETE             (NRuint)261
#define NR_KEY_RIGHT              (NRuint)262
#define NR_KEY_LEFT               (NRuint)263
#define NR_KEY_DOWN               (NRuint)264
#define NR_KEY_UP                 (NRuint)265
#define NR_KEY_PAGE_UP            (NRuint)266
#define NR_KEY_PAGE_DOWN          (NRuint)267
#define NR_KEY_HOME               (NRuint)268
#define NR_KEY_END                (NRuint)269
#define NR_KEY_CAPS_LOCK          (NRuint)280
#define NR_KEY_SCROLL_LOCK        (NRuint)281
#define NR_KEY_NUM_LOCK           (NRuint)282
#define NR_KEY_PRINT_SCREEN       (NRuint)283
#define NR_KEY_PAUSE              (NRuint)284
#define NR_KEY_F1                 (NRuint)290
#define NR_KEY_F2                 (NRuint)291
#define NR_KEY_F3                 (NRuint)292
#define NR_KEY_F4                 (NRuint)293
#define NR_KEY_F5                 (NRuint)294
#define NR_KEY_F6                 (NRuint)295
#define NR_KEY_F7                 (NRuint)296
#define NR_KEY_F8                 (NRuint)297
#define NR_KEY_F9                 (NRuint)298
#define NR_KEY_F10                (NRuint)299
#define NR_KEY_F11                (NRuint)300
#define NR_KEY_F12                (NRuint)301
#define NR_KEY_F13                (NRuint)302
#define NR_KEY_F14                (NRuint)303
#define NR_KEY_F15                (NRuint)304
#define NR_KEY_F16                (NRuint)305
#define NR_KEY_F17                (NRuint)306
#define NR_KEY_F18                (NRuint)307
#define NR_KEY_F19                (NRuint)308
#define NR_KEY_F20                (NRuint)309
#define NR_KEY_F21                (NRuint)310
#define NR_KEY_F22                (NRuint)311
#define NR_KEY_F23                (NRuint)312
#define NR_KEY_F24                (NRuint)313
#define NR_KEY_F25                (NRuint)314
#define NR_KEY_KP_0               (NRuint)320
#define NR_KEY_KP_1               (NRuint)321
#define NR_KEY_KP_2               (NRuint)322
#define NR_KEY_KP_3               (NRuint)323
#define NR_KEY_KP_4               (NRuint)324
#define NR_KEY_KP_5               (NRuint)325
#define NR_KEY_KP_6               (NRuint)326
#define NR_KEY_KP_7               (NRuint)327
#define NR_KEY_KP_8               (NRuint)328
#define NR_KEY_KP_9               (NRuint)329
#define NR_KEY_KP_DECIMAL         (NRuint)330
#define NR_KEY_KP_DIVIDE          (NRuint)331
#define NR_KEY_KP_MULTIPLY        (NRuint)332
#define NR_KEY_KP_SUBTRACT        (NRuint)333
#define NR_KEY_KP_ADD             (NRuint)334
#define NR_KEY_KP_ENTER           (NRuint)335
#define NR_KEY_KP_EQUAL           (NRuint)336
#define NR_KEY_LEFT_SHIFT         (NRuint)340
#define NR_KEY_LEFT_CONTROL       (NRuint)341
#define NR_KEY_LEFT_ALT           (NRuint)342
#define NR_KEY_LEFT_SUPER         (NRuint)343
#define NR_KEY_RIGHT_SHIFT        (NRuint)344
#define NR_KEY_RIGHT_CONTROL      (NRuint)345
#define NR_KEY_RIGHT_ALT          (NRuint)346
#define NR_KEY_RIGHT_SUPER        (NRuint)347
#define NR_KEY_MENU               (NRuint)348

}