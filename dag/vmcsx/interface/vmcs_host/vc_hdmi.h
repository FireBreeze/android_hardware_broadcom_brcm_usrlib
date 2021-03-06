/*=============================================================================
Copyright (c) 2008-2009 Broadcom Europe Limited.
All rights reserved.

Project  :  TV service
Module   :  Common host interface for HDMI
File     :  $Id: //software/customers/broadcom/mobcom/vc4/rel/interface/vmcs_host/vc_hdmi.h#8 $
Revision :  $Revision: #8 $

FILE DESCRIPTION
HDMI common host header for TV service, defines resolution code which host applications should
use for power up command for HDMI
=============================================================================*/

#ifndef _VC_HDMI_H_
#define _VC_HDMI_H_

typedef int VC_HDMI_BOOL_T;

/**
 * HDMI resolution groups. There are two main groups: 
 * CEA - the conventional HDMI ones like 720p
 * DMT - computer monitor resolutions like XGA
 */
typedef enum {
   HDMI_RES_GROUP_INVALID = 0, /**< Initialised value */
   HDMI_RES_GROUP_CEA,   /**< CEA - HDMI device */
   HDMI_RES_GROUP_DMT,   /**< DMT - computer monitors */
   HDMI_RES_GROUP_CUSTOM /**< Unused at the moment */
} HDMI_RES_GROUP_T;

/**
 *  CEA 861-B defined video code and aspect ratios for various HDMI modes 
 */
typedef enum {
   HDMI_ASPECT_UNKNOWN  = 0, /**< Unknown aspect ratio */
   HDMI_ASPECT_4_3      = 1, /**< 4:3  */
   HDMI_ASPECT_14_9     = 2, /**< 14:9 */
   HDMI_ASPECT_16_9     = 3  /**< 16:9 */
} HDMI_ASPECT_T;

/**
 * Display options set the bounding box (only used in CEA mode) 
 */
typedef struct {
   HDMI_ASPECT_T   aspect;
   /** Active area information - meanings as in CEA-861. */
   VC_HDMI_BOOL_T  vertical_bar_present;
   uint16_t        left_bar_width;
   uint16_t        right_bar_width;
   VC_HDMI_BOOL_T  horizontal_bar_present;
   uint16_t        top_bar_height;
   uint16_t        bottom_bar_height;
   /** S0/S1 flags as defined in CEA-861. */
   uint8_t         overscan_flags;
} HDMI_DISPLAY_OPTIONS_T;

/**
 * Copy protection for HDMI, only HDCP is available
 * This enum is to make it consistent with the enums 
 * SDTV_CP_MODE_T in vc_sdtv.h 
 */
typedef enum {
   HDMI_CP_NONE         = 0, /**< No copyprotection */
   HDMI_CP_HDCP         = 1  /**< HDCP 1.x */
} HDMI_CP_MODE_T;

/**
 *  HDMI operation modes
 */
typedef enum {
   HDMI_MODE_OFF,  /**< Off! */
   HDMI_MODE_DVI,  /**< DVI */
   HDMI_MODE_HDMI, /**< Normal HDMI */
   HDMI_MODE_3D    /**< HDMI 1.4a 3D */
} HDMI_MODE_T;

/**
 * Possible values for the Source Product Description type code (in SPD infoframe).
 * Taken from the CEA-861 spec.
 */
typedef enum {
   HDMI_SPD_TYPE_UNKNOWN,
   HDMI_SPD_TYPE_STB,           /**<Digital STB */
   HDMI_SPD_TYPE_DVD,           /**<DVD player */
   HDMI_SPD_TYPE_DVHS,          /**<D-VHS */
   HDMI_SPD_TYPE_HDD_RECORDER,  /**<HDD video recoder */
   HDMI_SPD_TYPE_DVC,           /**<DVC */
   HDMI_SPD_TYPE_DSC,           /**<DSC */
   HDMI_SPD_TYPE_VCD,           /**<Video CD */
   HDMI_SPD_TYPE_GAME,          /**<Game */
   HDMI_SPD_TYPE_PC,            /**<PC general */
   HDMI_SPD_TYPE_BD,            /**<Blu-Ray Disc */
   HDMI_SPD_TYPE_SACD,          /**<Super Audio CD */
   HDMI_SPD_TYPE_HDDVD,         /**<HD DVD */
   HDMI_SPD_TYPE_PMP            /**<Personal media player */
} HDMI_SPD_TYPE_CODE_T;

/**
 * Structure for SPD infoframe 
 */
typedef struct {
   char  *manufacturer;        /**< Manufacture name (up to 8 characters) */
   char  *description;         /**< Product name (up to 16 characters) */
   HDMI_SPD_TYPE_CODE_T type;  /**< Product type */
} HDMI_SPD_DATA_T;

/**
 * These are CEA mode numbers (sent in AVI infoframe) for different resolutions as define in CEA-861
 * 1080i at 100/120Hz (40,46) are supported by HDMI H/W but note we cannot 
 * display the debug overlay under these modes. 
 * Some modes have two codes, the first one has aspect ratio 4:3 and 
 * the second one (with "H" suffix") 16:9.
 * The modes with "4x", etc. are the same the corresponding "non-multiplied" modes 
 * but clocked at a higher pixel clock.
 */
typedef enum {
   HDMI_CEA_VGA             =  1,
   HDMI_CEA_480p60          =  2,
   HDMI_CEA_480p60H         =  3,
   HDMI_CEA_720p60          =  4,
   HDMI_CEA_1080i60         =  5,
   HDMI_CEA_480i60          =  6,
   HDMI_CEA_480i60H         =  7,
   HDMI_CEA_240p60          =  8,
   HDMI_CEA_240p60H         =  9,
   HDMI_CEA_480i60_4x       = 10,
   HDMI_CEA_480i60_4xH      = 11,
   HDMI_CEA_240p60_4x       = 12,
   HDMI_CEA_240p60_4xH      = 13,
   HDMI_CEA_480p60_2x       = 14,
   HDMI_CEA_480p60_2xH      = 15,
   HDMI_CEA_1080p60         = 16,
   HDMI_CEA_576p50          = 17,
   HDMI_CEA_576p50H         = 18,
   HDMI_CEA_720p50          = 19,
   HDMI_CEA_1080i50         = 20,
   HDMI_CEA_576i50          = 21,
   HDMI_CEA_576i50H         = 22,
   HDMI_CEA_288p50          = 23,
   HDMI_CEA_288p50H         = 24,
   HDMI_CEA_576i50_4x       = 25,
   HDMI_CEA_576i50_4xH      = 26,
   HDMI_CEA_288p50_4x       = 27,
   HDMI_CEA_288p50_4xH      = 28,
   HDMI_CEA_576p50_2x       = 29,
   HDMI_CEA_576p50_2xH      = 30,
   HDMI_CEA_1080p50         = 31,
   HDMI_CEA_1080p24         = 32,
   HDMI_CEA_1080p25         = 33,
   HDMI_CEA_1080p30         = 34,
   HDMI_CEA_480p60_4x       = 35,
   HDMI_CEA_480p60_4xH      = 36,
   HDMI_CEA_576p50_4x       = 37,
   HDMI_CEA_576p50_4xH      = 38,
   HDMI_CEA_1080i50_rb      = 39,
   HDMI_CEA_1080i100        = 40, 
   HDMI_CEA_720p100         = 41,
   HDMI_CEA_576p100         = 42,
   HDMI_CEA_576p100H        = 43,
   HDMI_CEA_576i100         = 44,
   HDMI_CEA_576i100H        = 45,
   HDMI_CEA_1080i120        = 46,
   HDMI_CEA_720p120         = 47,
   HDMI_CEA_480p120         = 48,
   HDMI_CEA_480p120H        = 49,
   HDMI_CEA_480i120         = 50,
   HDMI_CEA_480i120H        = 51,
   HDMI_CEA_576p200         = 52,
   HDMI_CEA_576p200H        = 53,
   HDMI_CEA_576i200         = 54,
   HDMI_CEA_576i200H        = 55,
   HDMI_CEA_480p240         = 56,
   HDMI_CEA_480p240H        = 57,
   HDMI_CEA_480i240         = 58,
   HDMI_CEA_480i240H        = 59,
   //Put more CEA codes here if we support in the future

   HDMI_CEA_OFF = 0xff /**<Special code to shutdown HDMI */

} HDMI_CEA_RES_CODE_T;

/**
 * These are the DMT modes from VESA. They are used for powering up
 * HDMI in DMT resolutions and are not sent in AVI infoframes.
 * Enum is ordered as ascending order of DMT id. 
 * All reduced blanking formats are 60Hz unless stated otherwise. 
 */
typedef enum {
   HDMI_DMT_640x350_85      = 0x1,  /**<640x350 */
   HDMI_DMT_640x400_85      = 0x2,  /**<640x400 */
   HDMI_DMT_IBM_VGA_85      = 0x3,  /**<720x400 */
   HDMI_DMT_VGA_60          = 0x4,  /**<640x480 (60Hz is same as VGA above) */
   HDMI_DMT_VGA_72          = 0x5,
   HDMI_DMT_VGA_75          = 0x6,
   HDMI_DMT_VGA_85          = 0x7,
   HDMI_DMT_SVGA_56         = 0x8,  /**<800x600 */
   HDMI_DMT_SVGA_60         = 0x9,
   HDMI_DMT_SVGA_72         = 0xA,
   HDMI_DMT_SVGA_75         = 0xB,
   HDMI_DMT_SVGA_85         = 0xC,
   HDMI_DMT_SVGA_120        = 0xD,
   HDMI_DMT_848x480_60      = 0xE,  /**<848x480 */
   HDMI_DMT_XGA_60          = 0x10, /**<1024x768 */
   HDMI_DMT_XGA_70          = 0x11,
   HDMI_DMT_XGA_75          = 0x12,
   HDMI_DMT_XGA_85          = 0x13,
   HDMI_DMT_XGA_120         = 0x14,
   HDMI_DMT_XGAP_75         = 0x15, /**<1152x864 */
   HDMI_DMT_WXGA_RB         = 0x16, /**<1280x768 reduced blanking */
   HDMI_DMT_WXGA_60         = 0x17, 
   HDMI_DMT_WXGA_75         = 0x18, 
   HDMI_DMT_WXGA_85         = 0x19, 
   HDMI_DMT_WXGA_120        = 0x1A, /**<120Hz with reduced blanking */
   HDMI_DMT_1280x800_RB     = 0x1B, /**<1280x800 reduced blanking */
   HDMI_DMT_1280x800_60     = 0x1C, 
   HDMI_DMT_1280x960_60     = 0x20, /**<1280x960 */
   HDMI_DMT_1280x960_85     = 0x21,
   HDMI_DMT_SXGA_60         = 0x23, /**<1280x1024 */
   HDMI_DMT_SXGA_75         = 0x24, 
   HDMI_DMT_SXGA_85         = 0x25,
   HDMI_DMT_1360x768_60     = 0x27, /**<1360x768 */
   HDMI_DMT_1360x768_120    = 0x28, /**<120 Hz with reduced blanking */
   HDMI_DMT_SXGAP_RB        = 0x29, /**<1400x1050 reduced blanking */
   HDMI_DMT_SXGAP_60        = 0x2A, 
   HDMI_DMT_SXGAP_75        = 0x2B,
   HDMI_DMT_1440x900_RB     = 0x2E, /**<1440x900 reduced blanking */
   HDMI_DMT_1440x900_60     = 0x2F,
   HDMI_DMT_1440x900_75     = 0x30,  
   HDMI_DMT_1440x900_85     = 0x31, 
   HDMI_DMT_UXGA_60         = 0x33, /**<1600x1200 60Hz */
   HDMI_DMT_SWXGAP_RB       = 0x39, /**<1680x1050 reduced blanking */
   HDMI_DMT_SWXGAP_60       = 0x3A, /**<1680x1050 60Hz */
   HDMI_DMT_WUXGA_RB        = 0x44, /**<1920x1200 reduced blanking */
   HDMI_DMT_1366x768_60     = 0x51, /**<1366x768 60Hz */
   HDMI_DMT_1080p_60        = 0x52, /**<Same as 1080p60 above */
   HDMI_DMT_1600x900_RB     = 0x53, /**<1600x900 reduced blanking */
   HDMI_DMT_720p_60         = 0x55, /**<Same as 720p60 above */
   HDMI_DMT_1366x768_RB     = 0x56, /**<1366x768 reduced blanking */
   //Put more DMT codes here if we support in the future

   HDMI_DMT_OFF = 0xff
} HDMI_DMT_RES_CODE_T;

/**
 * HDMI scanmode 
 */
typedef enum {
   HDMI_NONINTERLACED,
   HDMI_INTERLACED
} HDMI_INTERLACED_T;

/**
 * Preference for powering up HDMI using best mode
 * Note we will only use CEA modes for matching
 */
typedef enum {
   HDMI_MODE_MATCH_NONE          = 0x0, /**<No mode*/
   HDMI_MODE_MATCH_FRAMERATE     = 0x1, /**<Match based on frame rate */
   HDMI_MODE_MATCH_RESOLUTION    = 0x2, /**<Match based on resolution */
   HDMI_MODE_MATCH_SCANMODE      = 0x4  /**<Match based on scan mode */
} EDID_MODE_MATCH_FLAG_T;

/**
 * Audio support flags
 */
typedef enum {
   EDID_AUDIO_NO_SUPPORT         = (1 << 0), /**<No support for that format */
   EDID_AUDIO_CHAN_UNSUPPORTED   = (1 << 1), /**<max. no. of channels exceeded */
   EDID_AUDIO_FS_UNSUPPORTED     = (1 << 2), /**<no support for that sampling frequency */
   EDID_AUDIO_BR_UNSUPPORTED     = (1 << 3), /**<max. bitrate exceeded */
   EDID_AUDIO_SAMP_UNSUPPORTED   = (1 << 4), /**sample size unsupported (pcm only) */
} EDID_AUDIO_SUPPORT_FLAG_T;

/**
 * Enums for audio support in audio descriptor block (CEA only)
 * audio formats as specified in CEA Short Audio Descriptors
 */
typedef enum {
   EDID_AudioFormat_eReserved,      /**<Refer to header when set in audio info frame */
   EDID_AudioFormat_ePCM,           /**<Plain old PCM, mandatory for any audio support */
   EDID_AudioFormat_eAC3,           /**<AC3 */
   EDID_AudioFormat_eMPEG1,         /**<Mpeg layer 1 and 2 */
   EDID_AudioFormat_eMP3,           /**<Mpeg layer 3 */
   EDID_AudioFormat_eMPEG2,         /**<Mpeg 2 audio */
   EDID_AudioFormat_eAAC,           /**<AAC */
   EDID_AudioFormat_eDTS,           /**<DTS */
   EDID_AudioFormat_eATRAC,         /**<Sony proprietary */
   EDID_AudioFormat_eDSD,           /**<Super Audio CD 1-bit audio */
   EDID_AudioFormat_eEAC3,          /**<Dolby Digital + */
   EDID_AudioFormat_eDTS_HD,        /**<DTS-HD */
   EDID_AudioFormat_eMLP,           /**<Meridian Lossless Packing - for DVD audio */
   EDID_AudioFormat_eDST,           /**<Direct stream transfer - compressed super audio CD */
   EDID_AudioFormat_eWMAPRO,        /**<WMA Pro */
   EDID_AudioFormat_eExtended,      /**<Refer to byte 3 of audio db for coding extension type */

   EDID_AudioFormat_eMaxCount
} EDID_AudioFormat;

/**
 * If audio format is set to EDID_AudioFormat_eExtended,
 * this gives the extended audio type (see CEA-861E section 6.6.1)
 */
typedef enum {
   EDID_AudioCodingExtension_NONE    = 0x0, /** no extension, for audio format != Extended */
   EDID_AudioCodingExtension_HEAAC   = 0x1, /**<HE-AAC */
   EDID_AudioCodingExtension_HEAAC2  = 0x2, /**<HE-AAC v2 */
   EDID_AudioCodingExtension_MPEGSUR = 0x3, /**<MPEG Surround */
   
   EDID_AudioCodingExtension_max
} EDID_AudioCodingExtension;

/**
 * Audio sample rates as specified in CEA Short Audio Descriptors
 */
typedef enum {
   EDID_AudioSampleRate_eReferToHeader = 0x0,      /**<Only used in audio infoframe */
   EDID_AudioSampleRate_e32KHz         = (1 << 0), /**<32 kHz (mandatory) */
   EDID_AudioSampleRate_e44KHz         = (1 << 1), /**<44.1 kHz (mandatory) */
   EDID_AudioSampleRate_e48KHz         = (1 << 2), /**<48kHz (mandatory) */
   EDID_AudioSampleRate_e88KHz         = (1 << 3), /**<88.2 kHz */
   EDID_AudioSampleRate_e96KHz         = (1 << 4), /**<96kHz */
   EDID_AudioSampleRate_e176KHz        = (1 << 5), /**<176.4 kHz */
   EDID_AudioSampleRate_e192KHz        = (1 << 6)  /**<192 kHz */
} EDID_AudioSampleRate;

/**
 * Audio sample sizes (L-PCM) as specified in CEA Short Audio Descriptors
 */
typedef enum {
   EDID_AudioSampleSize_refertoheader = 0x0, /**<Only used in audio infoframe */
   EDID_AudioSampleSize_16bit         = 0x1, /**<16-bit samples (mandatory) */
   EDID_AudioSampleSize_20bit         = 0x2, /**<20-bit samples */
   EDID_AudioSampleSize_24bit         = 0x4  /**<24-bit samples */
} EDID_AudioSampleSize;

/**
 *  LFE feedback level as described in audio db
 */
typedef enum {
   EDID_AudioLFEFB_UNKNOWN = 0x0, /**<Refer to other information */
   EDID_AudioLFEFB_0dB     = 0x1, /**<0dB - same level as other channels */
   EDID_AudioLFEFB_10dB    = 0x2  /**<+10dB relative to other channels */
} EDID_AudioLFEFB;

/**
 * HDMI notifications (defined as a bit mask to be conveniently returned as a state), 
 * make sure this does not clash with the values in vc_sdtv.h
 * SDTV notifications start at bit 16.
 * These values are returned by the TV service in a callback.
 */
typedef enum {
   VC_HDMI_UNPLUGGED          = (1 << 0),  /**<HDMI cable is detached */
   VC_HDMI_STANDBY            = (1 << 1),  /**<HDMI cable is attached but not powered on */
   VC_HDMI_DVI                = (1 << 2),  /**<HDMI is on but in DVI mode (no audio) */
   VC_HDMI_HDMI               = (1 << 3),  /**<HDMI is on and HDMI mode is active */
   VC_HDMI_HDCP_UNAUTH        = (1 << 4),  /**<HDCP authentication is broken (e.g. Ri mismatched) or not active */
   VC_HDMI_HDCP_AUTH          = (1 << 5),  /**<HDCP is active */
   VC_HDMI_HDCP_KEY_DOWNLOAD  = (1 << 6),  /**<HDCP key download successful/fail */
   VC_HDMI_HDCP_SRM_DOWNLOAD  = (1 << 7),  /**<HDCP revocation list download successful/fail */

   VC_HDMI_HDMI_3D            = (1 << 15), /**<3D mode is active */
} VC_HDMI_NOTIFY_T;

/**
 * Callback reason and arguments from HDMI middleware
 * Each callback comes with two optional uint32_t parameters.
 * Reason                     param1       param2      remark
 * VC_HDMI_UNPLUGGED            -            -         cable is unplugged
 * VC_HDMI_STANDBY            CEA/DMT      mode code   cable is plugged in and peripheral powered off (preferred mode sent back if available)
 * VC_HDMI_DVI                CEA/DMT      mode code   DVI mode is active at said resolution
 * VC_HDMI_HDMI               CEA/DMT      mode code   HDMI mode is active at said resolution
 * VC_HDMI_HDCP_UNAUTH        HDCP_ERROR_T  retry?     HDCP is inactive, the error can be none if we actively disable HDCP, if retry is non-zero, HDCP will attempt to reauthenticate
 * VC_HDMI_HDCP_AUTH            -            -         HDCP is active
 * VC_HDMI_HDCP_KEY_DOWNLOAD  success?       -         HDCP key download success (zero) or not (non zero)
 * VC_HDMI_HDCP_SRM_DOWNLOAD  no. of keys    -         HDCP revocation list download set no. of keys (zero means failure)
 * VC_HDMI_HDMI_3D             TBD          TBD        HDMI 3D mode is active
 */

//Some constants which are required on host side
#define HDCP_KEY_BLOCK_SIZE 328 /* KSV, padding, device keys and hash. */
#define HDCP_KSV_LENGTH   5
#define EDID_BLOCKSIZE 128
#define HDMI_NUM_PACKET_BYTES 28 /* Size of HDMI infoframes minus the header */

//All CEC related constants now reside in vc_cec.h

/**
 * General callback function for both HDMI and HDCP middleware
 * reason is the notification nature
 * param1 and param2 have different meanings depending on the notification (see above)
 *
 * @param client_p is the callback context
 *
 * @param reason is the callback reason
 * 
 * @param param1 is the first callback argument (meaning as above)
 *
 * @param param2 is the second callback argument (meaning as above)
 * 
 * @return void
 */
typedef void (*HDMI_CALLBACK_T)(void *client_p, VC_HDMI_NOTIFY_T reason, uint32_t param1, uint32_t param2);

#endif
