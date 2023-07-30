#pragma once


// From glfw3.h
namespace Normal {

#define NR_KEY_SPACE              (uint32)32
#define NR_KEY_APOSTROPHE         (uint32)39  /* ' */
#define NR_KEY_COMMA              (uint32)44  /* , */
#define NR_KEY_MINUS              (uint32)45  /* - */
#define NR_KEY_PERIOD             (uint32)46  /* . */
#define NR_KEY_SLASH              (uint32)47  /* / */
#define NR_KEY_0                  (uint32)48
#define NR_KEY_1                  (uint32)49
#define NR_KEY_2                  (uint32)50
#define NR_KEY_3                  (uint32)51
#define NR_KEY_4                  (uint32)52
#define NR_KEY_5                  (uint32)53
#define NR_KEY_6                  (uint32)54
#define NR_KEY_7                  (uint32)55
#define NR_KEY_8                  (uint32)56
#define NR_KEY_9                  (uint32)57
#define NR_KEY_SEMICOLON          (uint32)59  /* ; */
#define NR_KEY_EQUAL              (uint32)61  /* = */
#define NR_KEY_A                  (uint32)65
#define NR_KEY_B                  (uint32)66
#define NR_KEY_C                  (uint32)67
#define NR_KEY_D                  (uint32)68
#define NR_KEY_E                  (uint32)69
#define NR_KEY_F                  (uint32)70
#define NR_KEY_G                  (uint32)71
#define NR_KEY_H                  (uint32)72
#define NR_KEY_I                  (uint32)73
#define NR_KEY_J                  (uint32)74
#define NR_KEY_K                  (uint32)75
#define NR_KEY_L                  (uint32)76
#define NR_KEY_M                  (uint32)77
#define NR_KEY_N                  (uint32)78
#define NR_KEY_O                  (uint32)79
#define NR_KEY_P                  (uint32)80
#define NR_KEY_Q                  (uint32)81
#define NR_KEY_R                  (uint32)82
#define NR_KEY_S                  (uint32)83
#define NR_KEY_T                  (uint32)84
#define NR_KEY_U                  (uint32)85
#define NR_KEY_V                  (uint32)86
#define NR_KEY_W                  (uint32)87
#define NR_KEY_X                  (uint32)88
#define NR_KEY_Y                  (uint32)89
#define NR_KEY_Z                  (uint32)90
#define NR_KEY_LEFT_BRACKET       (uint32)91  /* [ */
#define NR_KEY_BACKSLASH          (uint32)92  /* \ */
#define NR_KEY_RIGHT_BRACKET      (uint32)93  /* ] */
#define NR_KEY_GRAVE_ACCENT       (uint32)96  /* ` */
#define NR_KEY_WORLD_1            (uint32)161 /* non-US #1 */
#define NR_KEY_WORLD_2            (uint32)162 /* non-US #2 */

	/* Function keys */
#define NR_KEY_ESCAPE             (uint32)256
#define NR_KEY_ENTER              (uint32)257
#define NR_KEY_TAB                (uint32)258
#define NR_KEY_BACKSPACE          (uint32)259
#define NR_KEY_INSERT             (uint32)260
#define NR_KEY_DELETE             (uint32)261
#define NR_KEY_RIGHT              (uint32)262
#define NR_KEY_LEFT               (uint32)263
#define NR_KEY_DOWN               (uint32)264
#define NR_KEY_UP                 (uint32)265
#define NR_KEY_PAGE_UP            (uint32)266
#define NR_KEY_PAGE_DOWN          (uint32)267
#define NR_KEY_HOME               (uint32)268
#define NR_KEY_END                (uint32)269
#define NR_KEY_CAPS_LOCK          (uint32)280
#define NR_KEY_SCROLL_LOCK        (uint32)281
#define NR_KEY_NUM_LOCK           (uint32)282
#define NR_KEY_PRINT_SCREEN       (uint32)283
#define NR_KEY_PAUSE              (uint32)284
#define NR_KEY_F1                 (uint32)290
#define NR_KEY_F2                 (uint32)291
#define NR_KEY_F3                 (uint32)292
#define NR_KEY_F4                 (uint32)293
#define NR_KEY_F5                 (uint32)294
#define NR_KEY_F6                 (uint32)295
#define NR_KEY_F7                 (uint32)296
#define NR_KEY_F8                 (uint32)297
#define NR_KEY_F9                 (uint32)298
#define NR_KEY_F10                (uint32)299
#define NR_KEY_F11                (uint32)300
#define NR_KEY_F12                (uint32)301
#define NR_KEY_F13                (uint32)302
#define NR_KEY_F14                (uint32)303
#define NR_KEY_F15                (uint32)304
#define NR_KEY_F16                (uint32)305
#define NR_KEY_F17                (uint32)306
#define NR_KEY_F18                (uint32)307
#define NR_KEY_F19                (uint32)308
#define NR_KEY_F20                (uint32)309
#define NR_KEY_F21                (uint32)310
#define NR_KEY_F22                (uint32)311
#define NR_KEY_F23                (uint32)312
#define NR_KEY_F24                (uint32)313
#define NR_KEY_F25                (uint32)314
#define NR_KEY_KP_0               (uint32)320
#define NR_KEY_KP_1               (uint32)321
#define NR_KEY_KP_2               (uint32)322
#define NR_KEY_KP_3               (uint32)323
#define NR_KEY_KP_4               (uint32)324
#define NR_KEY_KP_5               (uint32)325
#define NR_KEY_KP_6               (uint32)326
#define NR_KEY_KP_7               (uint32)327
#define NR_KEY_KP_8               (uint32)328
#define NR_KEY_KP_9               (uint32)329
#define NR_KEY_KP_DECIMAL         (uint32)330
#define NR_KEY_KP_DIVIDE          (uint32)331
#define NR_KEY_KP_MULTIPLY        (uint32)332
#define NR_KEY_KP_SUBTRACT        (uint32)333
#define NR_KEY_KP_ADD             (uint32)334
#define NR_KEY_KP_ENTER           (uint32)335
#define NR_KEY_KP_EQUAL           (uint32)336
#define NR_KEY_LEFT_SHIFT         (uint32)340
#define NR_KEY_LEFT_CONTROL       (uint32)341
#define NR_KEY_LEFT_ALT           (uint32)342
#define NR_KEY_LEFT_SUPER         (uint32)343
#define NR_KEY_RIGHT_SHIFT        (uint32)344
#define NR_KEY_RIGHT_CONTROL      (uint32)345
#define NR_KEY_RIGHT_ALT          (uint32)346
#define NR_KEY_RIGHT_SUPER        (uint32)347
#define NR_KEY_MENU               (uint32)348

}