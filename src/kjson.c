
#line 1 "/home/xero/code/github.com/kJSON/src/kjson.rl"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "kjson.h"

struct kjson_parser_s {
    kjson_config_t config;
    int cs;
    int top;
    int stack[32]; // Fixed stack for now, should be dynamic or based on config
    const char* mark;
};


#line 15 "/home/xero/code/github.com/kJSON/src/kjson.c"
static const int kjson_start = 1;
static const int kjson_first_final = 624;
static const int kjson_error = 0;

static const int kjson_en_object = 13;
static const int kjson_en_array = 39;
static const int kjson_en_return_state = 611;
static const int kjson_en_value = 612;
static const int kjson_en_main = 1;


#line 140 "/home/xero/code/github.com/kJSON/src/kjson.rl"


kjson_parser_t* kjson_parser_create(kjson_config_t* config) {
    kjson_parser_t* parser = (kjson_parser_t*)malloc(sizeof(kjson_parser_t));
    if (!parser) return NULL;

    if (config) {
        parser->config = *config;
    } else {
        parser->config.max_depth = 32;
        parser->config.max_string_length = 1024;
        parser->config.allow_json5 = 1;
    }
    
    
#line 39 "/home/xero/code/github.com/kJSON/src/kjson.c"
	{
	( parser->cs) = kjson_start;
	( parser->top) = 0;
	}

#line 155 "/home/xero/code/github.com/kJSON/src/kjson.rl"
    
    return parser;
}

void kjson_parser_destroy(kjson_parser_t* parser) {
    if (parser) {
        free(parser);
    }
}

kjson_status_t kjson_parse(kjson_parser_t* parser, const char* data, size_t length, kjson_event_handlers_t* handlers, void* user_data) {
    if (!parser || !data) return KJSON_ERROR_INVALID_JSON;

    const char* p = data;
    const char* pe = data + length;
    const char* eof = pe;

    printf("Parsing: %.*s\n", (int)length, data);

    
#line 62 "/home/xero/code/github.com/kJSON/src/kjson.c"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( ( parser->cs) ) {
		case 1: goto st1;
		case 2: goto st2;
		case 624: goto st624;
		case 0: goto st0;
		case 3: goto st3;
		case 4: goto st4;
		case 5: goto st5;
		case 625: goto st625;
		case 6: goto st6;
		case 7: goto st7;
		case 626: goto st626;
		case 8: goto st8;
		case 9: goto st9;
		case 10: goto st10;
		case 11: goto st11;
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 15: goto st15;
		case 16: goto st16;
		case 17: goto st17;
		case 18: goto st18;
		case 19: goto st19;
		case 20: goto st20;
		case 21: goto st21;
		case 22: goto st22;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 627: goto st627;
		case 34: goto st34;
		case 35: goto st35;
		case 36: goto st36;
		case 37: goto st37;
		case 38: goto st38;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 42: goto st42;
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 49: goto st49;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 53: goto st53;
		case 54: goto st54;
		case 55: goto st55;
		case 56: goto st56;
		case 57: goto st57;
		case 58: goto st58;
		case 59: goto st59;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 63: goto st63;
		case 64: goto st64;
		case 65: goto st65;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 69: goto st69;
		case 628: goto st628;
		case 629: goto st629;
		case 70: goto st70;
		case 71: goto st71;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 630: goto st630;
		case 631: goto st631;
		case 632: goto st632;
		case 80: goto st80;
		case 633: goto st633;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 88: goto st88;
		case 89: goto st89;
		case 90: goto st90;
		case 634: goto st634;
		case 91: goto st91;
		case 92: goto st92;
		case 93: goto st93;
		case 94: goto st94;
		case 95: goto st95;
		case 96: goto st96;
		case 97: goto st97;
		case 635: goto st635;
		case 98: goto st98;
		case 99: goto st99;
		case 100: goto st100;
		case 101: goto st101;
		case 102: goto st102;
		case 103: goto st103;
		case 636: goto st636;
		case 104: goto st104;
		case 105: goto st105;
		case 106: goto st106;
		case 107: goto st107;
		case 108: goto st108;
		case 637: goto st637;
		case 109: goto st109;
		case 110: goto st110;
		case 111: goto st111;
		case 112: goto st112;
		case 113: goto st113;
		case 114: goto st114;
		case 115: goto st115;
		case 116: goto st116;
		case 117: goto st117;
		case 118: goto st118;
		case 119: goto st119;
		case 638: goto st638;
		case 120: goto st120;
		case 121: goto st121;
		case 639: goto st639;
		case 122: goto st122;
		case 123: goto st123;
		case 124: goto st124;
		case 125: goto st125;
		case 126: goto st126;
		case 127: goto st127;
		case 128: goto st128;
		case 129: goto st129;
		case 130: goto st130;
		case 131: goto st131;
		case 132: goto st132;
		case 133: goto st133;
		case 134: goto st134;
		case 135: goto st135;
		case 136: goto st136;
		case 137: goto st137;
		case 138: goto st138;
		case 640: goto st640;
		case 139: goto st139;
		case 140: goto st140;
		case 141: goto st141;
		case 142: goto st142;
		case 143: goto st143;
		case 144: goto st144;
		case 641: goto st641;
		case 145: goto st145;
		case 146: goto st146;
		case 147: goto st147;
		case 148: goto st148;
		case 149: goto st149;
		case 150: goto st150;
		case 642: goto st642;
		case 151: goto st151;
		case 152: goto st152;
		case 153: goto st153;
		case 154: goto st154;
		case 155: goto st155;
		case 156: goto st156;
		case 157: goto st157;
		case 158: goto st158;
		case 159: goto st159;
		case 160: goto st160;
		case 643: goto st643;
		case 161: goto st161;
		case 162: goto st162;
		case 163: goto st163;
		case 164: goto st164;
		case 165: goto st165;
		case 644: goto st644;
		case 645: goto st645;
		case 646: goto st646;
		case 166: goto st166;
		case 167: goto st167;
		case 647: goto st647;
		case 168: goto st168;
		case 169: goto st169;
		case 170: goto st170;
		case 171: goto st171;
		case 172: goto st172;
		case 173: goto st173;
		case 174: goto st174;
		case 175: goto st175;
		case 176: goto st176;
		case 648: goto st648;
		case 177: goto st177;
		case 178: goto st178;
		case 179: goto st179;
		case 180: goto st180;
		case 181: goto st181;
		case 649: goto st649;
		case 650: goto st650;
		case 651: goto st651;
		case 182: goto st182;
		case 183: goto st183;
		case 184: goto st184;
		case 185: goto st185;
		case 186: goto st186;
		case 187: goto st187;
		case 188: goto st188;
		case 189: goto st189;
		case 190: goto st190;
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
		case 197: goto st197;
		case 198: goto st198;
		case 199: goto st199;
		case 200: goto st200;
		case 201: goto st201;
		case 202: goto st202;
		case 203: goto st203;
		case 204: goto st204;
		case 205: goto st205;
		case 206: goto st206;
		case 207: goto st207;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 652: goto st652;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 221: goto st221;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 225: goto st225;
		case 226: goto st226;
		case 227: goto st227;
		case 228: goto st228;
		case 229: goto st229;
		case 230: goto st230;
		case 653: goto st653;
		case 231: goto st231;
		case 232: goto st232;
		case 233: goto st233;
		case 234: goto st234;
		case 235: goto st235;
		case 236: goto st236;
		case 237: goto st237;
		case 238: goto st238;
		case 239: goto st239;
		case 240: goto st240;
		case 654: goto st654;
		case 241: goto st241;
		case 242: goto st242;
		case 243: goto st243;
		case 244: goto st244;
		case 245: goto st245;
		case 246: goto st246;
		case 247: goto st247;
		case 248: goto st248;
		case 249: goto st249;
		case 250: goto st250;
		case 251: goto st251;
		case 252: goto st252;
		case 253: goto st253;
		case 254: goto st254;
		case 255: goto st255;
		case 256: goto st256;
		case 257: goto st257;
		case 258: goto st258;
		case 259: goto st259;
		case 260: goto st260;
		case 261: goto st261;
		case 262: goto st262;
		case 655: goto st655;
		case 263: goto st263;
		case 264: goto st264;
		case 265: goto st265;
		case 266: goto st266;
		case 267: goto st267;
		case 268: goto st268;
		case 269: goto st269;
		case 270: goto st270;
		case 271: goto st271;
		case 272: goto st272;
		case 273: goto st273;
		case 274: goto st274;
		case 656: goto st656;
		case 275: goto st275;
		case 276: goto st276;
		case 277: goto st277;
		case 278: goto st278;
		case 279: goto st279;
		case 657: goto st657;
		case 280: goto st280;
		case 281: goto st281;
		case 282: goto st282;
		case 283: goto st283;
		case 658: goto st658;
		case 284: goto st284;
		case 285: goto st285;
		case 659: goto st659;
		case 286: goto st286;
		case 287: goto st287;
		case 288: goto st288;
		case 289: goto st289;
		case 290: goto st290;
		case 291: goto st291;
		case 292: goto st292;
		case 293: goto st293;
		case 294: goto st294;
		case 295: goto st295;
		case 296: goto st296;
		case 660: goto st660;
		case 297: goto st297;
		case 298: goto st298;
		case 299: goto st299;
		case 300: goto st300;
		case 301: goto st301;
		case 661: goto st661;
		case 662: goto st662;
		case 302: goto st302;
		case 303: goto st303;
		case 304: goto st304;
		case 305: goto st305;
		case 306: goto st306;
		case 307: goto st307;
		case 308: goto st308;
		case 309: goto st309;
		case 310: goto st310;
		case 311: goto st311;
		case 312: goto st312;
		case 313: goto st313;
		case 314: goto st314;
		case 663: goto st663;
		case 315: goto st315;
		case 316: goto st316;
		case 317: goto st317;
		case 318: goto st318;
		case 319: goto st319;
		case 320: goto st320;
		case 321: goto st321;
		case 322: goto st322;
		case 323: goto st323;
		case 324: goto st324;
		case 325: goto st325;
		case 326: goto st326;
		case 327: goto st327;
		case 664: goto st664;
		case 328: goto st328;
		case 329: goto st329;
		case 330: goto st330;
		case 331: goto st331;
		case 332: goto st332;
		case 333: goto st333;
		case 334: goto st334;
		case 335: goto st335;
		case 336: goto st336;
		case 337: goto st337;
		case 338: goto st338;
		case 339: goto st339;
		case 340: goto st340;
		case 341: goto st341;
		case 342: goto st342;
		case 343: goto st343;
		case 344: goto st344;
		case 345: goto st345;
		case 346: goto st346;
		case 347: goto st347;
		case 348: goto st348;
		case 349: goto st349;
		case 665: goto st665;
		case 350: goto st350;
		case 351: goto st351;
		case 352: goto st352;
		case 353: goto st353;
		case 354: goto st354;
		case 666: goto st666;
		case 355: goto st355;
		case 356: goto st356;
		case 357: goto st357;
		case 358: goto st358;
		case 359: goto st359;
		case 360: goto st360;
		case 361: goto st361;
		case 667: goto st667;
		case 362: goto st362;
		case 363: goto st363;
		case 364: goto st364;
		case 365: goto st365;
		case 366: goto st366;
		case 367: goto st367;
		case 668: goto st668;
		case 368: goto st368;
		case 369: goto st369;
		case 370: goto st370;
		case 371: goto st371;
		case 372: goto st372;
		case 373: goto st373;
		case 669: goto st669;
		case 374: goto st374;
		case 375: goto st375;
		case 376: goto st376;
		case 377: goto st377;
		case 378: goto st378;
		case 379: goto st379;
		case 380: goto st380;
		case 381: goto st381;
		case 382: goto st382;
		case 383: goto st383;
		case 670: goto st670;
		case 384: goto st384;
		case 385: goto st385;
		case 386: goto st386;
		case 387: goto st387;
		case 388: goto st388;
		case 671: goto st671;
		case 672: goto st672;
		case 389: goto st389;
		case 390: goto st390;
		case 391: goto st391;
		case 392: goto st392;
		case 393: goto st393;
		case 394: goto st394;
		case 395: goto st395;
		case 396: goto st396;
		case 397: goto st397;
		case 398: goto st398;
		case 399: goto st399;
		case 400: goto st400;
		case 401: goto st401;
		case 673: goto st673;
		case 402: goto st402;
		case 403: goto st403;
		case 404: goto st404;
		case 405: goto st405;
		case 406: goto st406;
		case 407: goto st407;
		case 408: goto st408;
		case 409: goto st409;
		case 410: goto st410;
		case 411: goto st411;
		case 412: goto st412;
		case 413: goto st413;
		case 414: goto st414;
		case 674: goto st674;
		case 415: goto st415;
		case 416: goto st416;
		case 417: goto st417;
		case 418: goto st418;
		case 419: goto st419;
		case 420: goto st420;
		case 421: goto st421;
		case 422: goto st422;
		case 423: goto st423;
		case 424: goto st424;
		case 425: goto st425;
		case 426: goto st426;
		case 427: goto st427;
		case 428: goto st428;
		case 429: goto st429;
		case 430: goto st430;
		case 431: goto st431;
		case 432: goto st432;
		case 433: goto st433;
		case 434: goto st434;
		case 675: goto st675;
		case 435: goto st435;
		case 436: goto st436;
		case 437: goto st437;
		case 438: goto st438;
		case 439: goto st439;
		case 440: goto st440;
		case 441: goto st441;
		case 442: goto st442;
		case 443: goto st443;
		case 444: goto st444;
		case 676: goto st676;
		case 445: goto st445;
		case 446: goto st446;
		case 447: goto st447;
		case 448: goto st448;
		case 449: goto st449;
		case 450: goto st450;
		case 451: goto st451;
		case 452: goto st452;
		case 453: goto st453;
		case 454: goto st454;
		case 455: goto st455;
		case 456: goto st456;
		case 457: goto st457;
		case 458: goto st458;
		case 459: goto st459;
		case 460: goto st460;
		case 461: goto st461;
		case 462: goto st462;
		case 463: goto st463;
		case 464: goto st464;
		case 465: goto st465;
		case 466: goto st466;
		case 677: goto st677;
		case 467: goto st467;
		case 468: goto st468;
		case 469: goto st469;
		case 470: goto st470;
		case 471: goto st471;
		case 678: goto st678;
		case 472: goto st472;
		case 473: goto st473;
		case 474: goto st474;
		case 475: goto st475;
		case 476: goto st476;
		case 477: goto st477;
		case 478: goto st478;
		case 679: goto st679;
		case 479: goto st479;
		case 480: goto st480;
		case 481: goto st481;
		case 482: goto st482;
		case 483: goto st483;
		case 484: goto st484;
		case 680: goto st680;
		case 485: goto st485;
		case 486: goto st486;
		case 487: goto st487;
		case 488: goto st488;
		case 489: goto st489;
		case 490: goto st490;
		case 681: goto st681;
		case 491: goto st491;
		case 492: goto st492;
		case 493: goto st493;
		case 494: goto st494;
		case 495: goto st495;
		case 496: goto st496;
		case 497: goto st497;
		case 498: goto st498;
		case 499: goto st499;
		case 500: goto st500;
		case 682: goto st682;
		case 501: goto st501;
		case 502: goto st502;
		case 503: goto st503;
		case 504: goto st504;
		case 505: goto st505;
		case 683: goto st683;
		case 684: goto st684;
		case 506: goto st506;
		case 507: goto st507;
		case 508: goto st508;
		case 509: goto st509;
		case 510: goto st510;
		case 511: goto st511;
		case 512: goto st512;
		case 513: goto st513;
		case 514: goto st514;
		case 515: goto st515;
		case 516: goto st516;
		case 517: goto st517;
		case 518: goto st518;
		case 685: goto st685;
		case 519: goto st519;
		case 520: goto st520;
		case 521: goto st521;
		case 522: goto st522;
		case 523: goto st523;
		case 524: goto st524;
		case 525: goto st525;
		case 526: goto st526;
		case 527: goto st527;
		case 528: goto st528;
		case 529: goto st529;
		case 530: goto st530;
		case 531: goto st531;
		case 686: goto st686;
		case 532: goto st532;
		case 533: goto st533;
		case 534: goto st534;
		case 535: goto st535;
		case 536: goto st536;
		case 537: goto st537;
		case 538: goto st538;
		case 539: goto st539;
		case 540: goto st540;
		case 541: goto st541;
		case 542: goto st542;
		case 543: goto st543;
		case 544: goto st544;
		case 545: goto st545;
		case 546: goto st546;
		case 547: goto st547;
		case 548: goto st548;
		case 549: goto st549;
		case 550: goto st550;
		case 551: goto st551;
		case 552: goto st552;
		case 553: goto st553;
		case 687: goto st687;
		case 554: goto st554;
		case 555: goto st555;
		case 556: goto st556;
		case 557: goto st557;
		case 558: goto st558;
		case 688: goto st688;
		case 559: goto st559;
		case 560: goto st560;
		case 561: goto st561;
		case 562: goto st562;
		case 563: goto st563;
		case 564: goto st564;
		case 565: goto st565;
		case 689: goto st689;
		case 566: goto st566;
		case 567: goto st567;
		case 568: goto st568;
		case 569: goto st569;
		case 570: goto st570;
		case 571: goto st571;
		case 690: goto st690;
		case 572: goto st572;
		case 573: goto st573;
		case 574: goto st574;
		case 575: goto st575;
		case 576: goto st576;
		case 577: goto st577;
		case 691: goto st691;
		case 578: goto st578;
		case 579: goto st579;
		case 580: goto st580;
		case 581: goto st581;
		case 582: goto st582;
		case 583: goto st583;
		case 584: goto st584;
		case 585: goto st585;
		case 586: goto st586;
		case 587: goto st587;
		case 692: goto st692;
		case 588: goto st588;
		case 589: goto st589;
		case 590: goto st590;
		case 591: goto st591;
		case 592: goto st592;
		case 693: goto st693;
		case 694: goto st694;
		case 593: goto st593;
		case 594: goto st594;
		case 595: goto st595;
		case 596: goto st596;
		case 597: goto st597;
		case 598: goto st598;
		case 599: goto st599;
		case 600: goto st600;
		case 601: goto st601;
		case 602: goto st602;
		case 603: goto st603;
		case 604: goto st604;
		case 605: goto st605;
		case 695: goto st695;
		case 606: goto st606;
		case 607: goto st607;
		case 608: goto st608;
		case 609: goto st609;
		case 610: goto st610;
		case 611: goto st611;
		case 612: goto st612;
		case 613: goto st613;
		case 696: goto st696;
		case 614: goto st614;
		case 615: goto st615;
		case 616: goto st616;
		case 697: goto st697;
		case 617: goto st617;
		case 618: goto st618;
		case 698: goto st698;
		case 619: goto st619;
		case 620: goto st620;
		case 621: goto st621;
		case 622: goto st622;
		case 623: goto st623;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( ( parser->cs) )
	{
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 13: goto st1;
		case 32: goto st1;
		case 34: goto tr2;
		case 39: goto tr3;
		case 44: goto st0;
		case 47: goto tr5;
		case 58: goto st0;
		case 91: goto tr6;
		case 93: goto st0;
		case 123: goto tr7;
		case 125: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st1;
	goto tr0;
tr0:
#line 76 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ parser->mark = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 803 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr9;
		case 32: goto tr9;
		case 34: goto tr9;
		case 44: goto tr9;
		case 47: goto tr9;
		case 58: goto tr9;
		case 91: goto tr9;
		case 93: goto tr9;
		case 123: goto tr9;
		case 125: goto tr9;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr9;
	goto st2;
tr6:
#line 37 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_start) 
            handlers->on_array_start(p - data, user_data);
    }
#line 135 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->stack)[( parser->top)++] = 624;goto st39;} }
	goto st624;
tr7:
#line 27 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_object_start) 
            handlers->on_object_start(p - data, user_data);
    }
#line 134 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->stack)[( parser->top)++] = 624;goto st13;} }
	goto st624;
tr9:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 91 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; }
	goto st624;
tr11:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
	goto st624;
st624:
	if ( ++p == pe )
		goto _test_eof624;
case 624:
#line 851 "/home/xero/code/github.com/kJSON/src/kjson.c"
	goto st0;
st0:
( parser->cs) = 0;
	goto _out;
tr2:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 865 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 34: goto tr11;
		case 92: goto st4;
	}
	goto st3;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	goto st3;
tr3:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
#line 76 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ parser->mark = p; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 886 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr14;
		case 32: goto tr14;
		case 34: goto tr14;
		case 39: goto tr15;
		case 44: goto tr14;
		case 47: goto tr14;
		case 58: goto tr14;
		case 92: goto st8;
		case 123: goto tr14;
		case 125: goto tr14;
	}
	if ( (*p) > 10 ) {
		if ( 91 <= (*p) && (*p) <= 93 )
			goto tr14;
	} else if ( (*p) >= 9 )
		goto tr14;
	goto st5;
tr14:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 91 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; }
	goto st625;
st625:
	if ( ++p == pe )
		goto _test_eof625;
case 625:
#line 916 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 39: goto tr11;
		case 92: goto st7;
	}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 39: goto tr11;
		case 92: goto st7;
	}
	goto st6;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	goto st6;
tr15:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
	goto st626;
st626:
	if ( ++p == pe )
		goto _test_eof626;
case 626:
#line 946 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr9;
		case 32: goto tr9;
		case 34: goto tr9;
		case 44: goto tr9;
		case 47: goto tr9;
		case 58: goto tr9;
		case 91: goto tr9;
		case 93: goto tr9;
		case 123: goto tr9;
		case 125: goto tr9;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr9;
	goto st2;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 13: goto tr14;
		case 32: goto tr14;
		case 34: goto tr14;
		case 44: goto tr14;
		case 47: goto tr14;
		case 58: goto tr14;
		case 91: goto tr14;
		case 93: goto tr14;
		case 123: goto tr14;
		case 125: goto tr14;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr14;
	goto st5;
tr5:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 987 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st10;
		case 47: goto st12;
	}
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 42 )
		goto st11;
	goto st10;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 42: goto st11;
		case 47: goto st1;
	}
	goto st10;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 10 )
		goto st1;
	goto st12;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 13: goto st13;
		case 32: goto st13;
		case 34: goto tr23;
		case 36: goto tr24;
		case 39: goto tr25;
		case 47: goto tr26;
		case 95: goto tr24;
		case 125: goto tr27;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st13;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr24;
	} else
		goto tr24;
	goto st0;
tr23:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 1048 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 34: goto st15;
		case 92: goto st34;
	}
	goto st14;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 13: goto tr31;
		case 32: goto tr31;
		case 47: goto tr32;
		case 58: goto tr33;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr31;
	goto st0;
tr31:
#line 47 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_key)
            handlers->on_key(parser->mark, p - parser->mark, user_data);
    }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 1076 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st16;
		case 32: goto st16;
		case 47: goto tr35;
		case 58: goto tr36;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st16;
	goto st0;
tr35:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st17;
tr32:
#line 47 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_key)
            handlers->on_key(parser->mark, p - parser->mark, user_data);
    }
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 1099 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st18;
		case 47: goto st20;
	}
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 42 )
		goto st19;
	goto st18;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 42: goto st19;
		case 47: goto st16;
	}
	goto st18;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 10 )
		goto st16;
	goto st20;
tr33:
#line 47 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_key)
            handlers->on_key(parser->mark, p - parser->mark, user_data);
    }
#line 73 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->stack)[( parser->top)++] = 21;goto st612;} }
	goto st21;
tr36:
#line 73 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->stack)[( parser->top)++] = 21;goto st612;} }
	goto st21;
tr45:
#line 32 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_object_end) 
            handlers->on_object_end(p - data, user_data);
    }
#line 100 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 1148 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st21;
		case 32: goto st21;
		case 44: goto st22;
		case 47: goto tr42;
		case 125: goto tr43;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st21;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 13: goto st22;
		case 32: goto st22;
		case 34: goto tr23;
		case 36: goto tr24;
		case 39: goto tr25;
		case 47: goto tr44;
		case 95: goto tr24;
		case 125: goto tr45;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr24;
	} else
		goto tr24;
	goto st0;
tr24:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 1190 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr31;
		case 32: goto tr31;
		case 36: goto st23;
		case 47: goto tr32;
		case 58: goto tr33;
		case 95: goto st23;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr31;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st23;
		} else if ( (*p) >= 65 )
			goto st23;
	} else
		goto st23;
	goto st0;
tr25:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 1220 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 39: goto st15;
		case 92: goto st25;
	}
	goto st24;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	goto st24;
tr44:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 1237 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st27;
		case 47: goto st29;
	}
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 42 )
		goto st28;
	goto st27;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 42: goto st28;
		case 47: goto st22;
	}
	goto st27;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 10 )
		goto st22;
	goto st29;
tr42:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1272 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st31;
		case 47: goto st33;
	}
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 42 )
		goto st32;
	goto st31;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 42: goto st32;
		case 47: goto st21;
	}
	goto st31;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 10 )
		goto st21;
	goto st33;
tr27:
#line 32 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_object_end) 
            handlers->on_object_end(p - data, user_data);
    }
#line 96 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st627;
tr43:
#line 32 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_object_end) 
            handlers->on_object_end(p - data, user_data);
    }
#line 102 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st627;
st627:
	if ( ++p == pe )
		goto _test_eof627;
case 627:
#line 1318 "/home/xero/code/github.com/kJSON/src/kjson.c"
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	goto st14;
tr26:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1331 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st36;
		case 47: goto st38;
	}
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) == 42 )
		goto st37;
	goto st36;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 42: goto st37;
		case 47: goto st13;
	}
	goto st36;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 10 )
		goto st13;
	goto st38;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 13: goto st39;
		case 32: goto st39;
		case 47: goto tr60;
		case 93: goto tr61;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st39;
	goto tr58;
tr58:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 40;goto st612;} }
	goto st40;
tr67:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1386 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 44: goto st41;
		case 47: goto tr64;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 13: goto st41;
		case 32: goto st41;
		case 47: goto tr66;
		case 93: goto tr67;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st41;
	goto tr58;
tr66:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 42;goto st612;} }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1417 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st43;
		case 44: goto st41;
		case 47: goto tr69;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 42 )
		goto st44;
	goto st43;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 42: goto st44;
		case 47: goto st41;
	}
	goto st43;
tr69:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1451 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st41;
		case 42: goto st47;
		case 47: goto st64;
	}
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 10 )
		goto st41;
	goto st46;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 10: goto st48;
		case 42: goto st106;
	}
	goto st47;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 13: goto st48;
		case 32: goto st48;
		case 42: goto tr77;
		case 47: goto tr78;
		case 93: goto tr79;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st48;
	goto tr76;
tr76:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 49;goto st612;} }
	goto st49;
tr79:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1501 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st51;
		case 44: goto st48;
		case 47: goto tr83;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 42 )
		goto st51;
	goto st50;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 42: goto st51;
		case 47: goto st40;
	}
	goto st50;
tr83:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 1535 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st53;
		case 47: goto st54;
	}
	goto st50;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 42: goto st51;
		case 47: goto st49;
	}
	goto st50;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 10: goto st49;
		case 42: goto st55;
	}
	goto st54;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 10: goto st49;
		case 42: goto st55;
		case 47: goto st56;
	}
	goto st54;
tr93:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 56;goto st612;} }
	goto st56;
tr96:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 1582 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 44: goto st58;
		case 47: goto tr91;
		case 93: goto tr92;
	}
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 10 )
		goto st40;
	goto st57;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 9: goto st58;
		case 10: goto st59;
		case 13: goto st58;
		case 32: goto st58;
		case 47: goto tr95;
		case 93: goto tr96;
	}
	goto tr93;
tr97:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 59;goto st612;} }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1619 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st59;
		case 32: goto st59;
		case 44: goto tr97;
		case 47: goto tr98;
		case 93: goto tr99;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st59;
	goto tr58;
tr98:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 60;goto st612;} }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 1637 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st61;
		case 44: goto st41;
		case 47: goto tr101;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 42 )
		goto st62;
	goto st61;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st59;
	}
	goto st61;
tr101:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 1671 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st59;
		case 42: goto st65;
	}
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 10 )
		goto st59;
	goto st64;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 10: goto st66;
		case 42: goto st141;
	}
	goto st65;
tr106:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 66;goto st612;} }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1699 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st66;
		case 32: goto st66;
		case 42: goto tr77;
		case 44: goto tr106;
		case 47: goto tr107;
		case 93: goto tr108;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st66;
	goto tr76;
tr77:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 67;goto st612;} }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 1717 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st51;
		case 44: goto st48;
		case 47: goto tr109;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
tr109:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 1735 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st50;
		case 44: goto st41;
		case 47: goto tr91;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
tr91:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 1753 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st40;
		case 42: goto st54;
	}
	goto st57;
tr61:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st628;
tr65:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st628;
tr283:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st628;
st628:
	if ( ++p == pe )
		goto _test_eof628;
case 628:
#line 1784 "/home/xero/code/github.com/kJSON/src/kjson.c"
	goto st0;
tr275:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st629;
tr84:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st629;
tr289:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st629;
st629:
	if ( ++p == pe )
		goto _test_eof629;
case 629:
#line 1811 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st51;
	goto st50;
tr107:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 70;goto st612;} }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 1822 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st71;
		case 44: goto st48;
		case 47: goto tr111;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st72;
	}
	goto st61;
tr116:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 72;goto st612;} }
	goto st72;
tr119:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 1856 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st62;
		case 44: goto st73;
		case 47: goto tr114;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 13: goto st73;
		case 32: goto st73;
		case 42: goto tr117;
		case 47: goto tr118;
		case 93: goto tr119;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st73;
	goto tr116;
tr117:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 74;goto st612;} }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 1888 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st62;
		case 44: goto st73;
		case 47: goto tr120;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
tr120:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 1906 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st59;
		case 32: goto st59;
		case 42: goto tr76;
		case 44: goto tr97;
		case 47: goto tr121;
		case 93: goto tr99;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st59;
	goto tr58;
tr121:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 76;goto st612;} }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 1925 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st77;
		case 44: goto st58;
		case 47: goto tr101;
		case 93: goto tr92;
	}
	goto st57;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 10: goto st72;
		case 42: goto st78;
	}
	goto st77;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 10: goto st72;
		case 42: goto st78;
		case 47: goto st79;
	}
	goto st77;
tr125:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 79;goto st612;} }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1962 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 10: goto st59;
		case 13: goto st79;
		case 32: goto st79;
		case 44: goto tr125;
		case 47: goto tr121;
		case 93: goto tr126;
	}
	goto tr93;
tr126:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st630;
tr336:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st630;
tr615:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st630;
st630:
	if ( ++p == pe )
		goto _test_eof630;
case 630:
#line 2001 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 44: goto st58;
		case 47: goto tr91;
		case 93: goto tr92;
	}
	goto st57;
tr584:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st631;
tr92:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st631;
tr305:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st631;
st631:
	if ( ++p == pe )
		goto _test_eof631;
case 631:
#line 2037 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st40;
	goto st57;
tr99:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st632;
tr313:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st632;
tr592:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st632;
st632:
	if ( ++p == pe )
		goto _test_eof632;
case 632:
#line 2069 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 44: goto st41;
		case 47: goto tr64;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
tr64:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 2086 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st50;
		case 47: goto st57;
	}
	goto st0;
tr753:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st633;
tr115:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st633;
tr474:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st633;
st633:
	if ( ++p == pe )
		goto _test_eof633;
case 633:
#line 2117 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st62;
	goto st61;
tr118:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 81;goto st612;} }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2128 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st82;
		case 44: goto st73;
		case 47: goto tr128;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st83;
	}
	goto st61;
tr132:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 83;goto st612;} }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2155 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st83;
		case 32: goto st83;
		case 42: goto tr131;
		case 44: goto tr132;
		case 47: goto tr133;
		case 93: goto tr134;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st83;
	goto tr130;
tr130:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 84;goto st612;} }
	goto st84;
tr140:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2180 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st44;
		case 44: goto st85;
		case 47: goto tr137;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 13: goto st85;
		case 32: goto st85;
		case 42: goto tr131;
		case 47: goto tr139;
		case 93: goto tr140;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st85;
	goto tr130;
tr131:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 86;goto st612;} }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2212 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st44;
		case 44: goto st85;
		case 47: goto tr141;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
tr141:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2230 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st41;
		case 32: goto st41;
		case 42: goto tr76;
		case 47: goto tr95;
		case 93: goto tr67;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st41;
	goto tr58;
tr95:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 88;goto st612;} }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2248 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st89;
		case 44: goto st58;
		case 47: goto tr101;
		case 93: goto tr92;
	}
	goto st57;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 10: goto st84;
		case 42: goto st90;
	}
	goto st89;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 10: goto st84;
		case 42: goto st90;
		case 47: goto st58;
	}
	goto st89;
tr736:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st634;
tr138:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st634;
tr457:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st634;
st634:
	if ( ++p == pe )
		goto _test_eof634;
case 634:
#line 2304 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st44;
	goto st43;
tr139:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 91;goto st612;} }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2315 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st92;
		case 44: goto st85;
		case 47: goto tr145;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 42: goto st44;
		case 47: goto st85;
	}
	goto st43;
tr145:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 2342 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st85;
		case 42: goto st99;
		case 47: goto st120;
	}
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 10: goto st85;
		case 42: goto st95;
	}
	goto st94;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 10: goto st85;
		case 42: goto st95;
		case 47: goto st96;
	}
	goto st94;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 9: goto st96;
		case 10: goto st41;
		case 13: goto st96;
		case 32: goto st96;
		case 47: goto tr152;
		case 93: goto tr153;
	}
	goto tr151;
tr151:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 97;goto st612;} }
	goto st97;
tr153:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 2394 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 44: goto st96;
		case 47: goto tr69;
		case 93: goto tr155;
	}
	goto st46;
tr833:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st635;
tr155:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st635;
tr554:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st635;
st635:
	if ( ++p == pe )
		goto _test_eof635;
case 635:
#line 2430 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st41;
	goto st46;
tr152:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 98;goto st612;} }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 2441 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st94;
		case 44: goto st96;
		case 47: goto tr69;
		case 93: goto tr155;
	}
	goto st46;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st104;
	}
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
	}
	goto st100;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st102;
	}
	goto st100;
tr160:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 102;goto st612;} }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 2488 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st102;
		case 10: goto st59;
		case 13: goto st102;
		case 32: goto st102;
		case 44: goto tr160;
		case 47: goto tr161;
		case 93: goto tr162;
	}
	goto tr151;
tr161:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 103;goto st612;} }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 2506 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st100;
		case 44: goto st96;
		case 47: goto tr101;
		case 93: goto tr155;
	}
	goto st46;
tr162:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st636;
tr438:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st636;
tr717:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st636;
st636:
	if ( ++p == pe )
		goto _test_eof636;
case 636:
#line 2546 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 44: goto st96;
		case 47: goto tr69;
		case 93: goto tr155;
	}
	goto st46;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 9: goto st104;
		case 10: goto st48;
		case 13: goto st104;
		case 32: goto st104;
		case 42: goto tr164;
		case 47: goto tr165;
		case 93: goto tr166;
	}
	goto tr163;
tr163:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 105;goto st612;} }
	goto st105;
tr166:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 2584 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st106;
		case 44: goto st104;
		case 47: goto tr168;
		case 93: goto tr169;
	}
	goto st47;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 10: goto st48;
		case 42: goto st106;
		case 47: goto st97;
	}
	goto st47;
tr168:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 2612 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st48;
		case 42: goto st108;
		case 47: goto st65;
	}
	goto st47;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 10: goto st48;
		case 42: goto st106;
		case 47: goto st105;
	}
	goto st47;
tr836:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st637;
tr169:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st637;
tr557:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st637;
st637:
	if ( ++p == pe )
		goto _test_eof637;
case 637:
#line 2654 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st48;
		case 42: goto st106;
	}
	goto st47;
tr164:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 109;goto st612;} }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 2666 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st106;
		case 44: goto st104;
		case 47: goto tr171;
		case 93: goto tr169;
	}
	goto st47;
tr171:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 2684 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st47;
		case 44: goto st96;
		case 47: goto tr101;
		case 93: goto tr155;
	}
	goto st46;
tr165:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 111;goto st612;} }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 2703 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st112;
		case 44: goto st104;
		case 47: goto tr168;
		case 93: goto tr169;
	}
	goto st47;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st113;
	}
	goto st100;
tr176:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 113;goto st612;} }
	goto st113;
tr179:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 2738 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st95;
		case 44: goto st114;
		case 47: goto tr145;
		case 93: goto tr175;
	}
	goto st94;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 9: goto st114;
		case 10: goto st85;
		case 13: goto st114;
		case 32: goto st114;
		case 42: goto tr177;
		case 47: goto tr178;
		case 93: goto tr179;
	}
	goto tr176;
tr177:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 115;goto st612;} }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 2770 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st95;
		case 44: goto st114;
		case 47: goto tr180;
		case 93: goto tr175;
	}
	goto st94;
tr180:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 2788 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st96;
		case 10: goto st41;
		case 13: goto st96;
		case 32: goto st96;
		case 42: goto tr163;
		case 47: goto tr181;
		case 93: goto tr153;
	}
	goto tr151;
tr181:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 117;goto st612;} }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 2806 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st120;
		case 44: goto st119;
		case 47: goto tr101;
		case 93: goto tr184;
	}
	goto st64;
tr185:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 118;goto st612;} }
	goto st118;
tr186:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 2831 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 44: goto st119;
		case 47: goto tr101;
		case 93: goto tr184;
	}
	goto st64;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 9: goto st119;
		case 10: goto st59;
		case 13: goto st119;
		case 32: goto st119;
		case 47: goto tr181;
		case 93: goto tr186;
	}
	goto tr185;
tr767:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st638;
tr184:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st638;
tr488:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st638;
st638:
	if ( ++p == pe )
		goto _test_eof638;
case 638:
#line 2880 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st59;
	goto st64;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 10: goto st83;
		case 42: goto st121;
	}
	goto st120;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 10: goto st83;
		case 42: goto st121;
		case 47: goto st119;
	}
	goto st120;
tr849:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st639;
tr175:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st639;
tr570:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st639;
st639:
	if ( ++p == pe )
		goto _test_eof639;
case 639:
#line 2928 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st85;
		case 42: goto st95;
	}
	goto st94;
tr178:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 122;goto st612;} }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 2941 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st123;
		case 44: goto st114;
		case 47: goto tr145;
		case 93: goto tr175;
	}
	goto st94;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 10: goto st85;
		case 42: goto st95;
		case 47: goto st114;
	}
	goto st94;
tr137:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 2969 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st125;
		case 47: goto st89;
	}
	goto st43;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st48;
	}
	goto st61;
tr133:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 126;goto st612;} }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 2991 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st127;
		case 44: goto st85;
		case 47: goto tr191;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st73;
	}
	goto st61;
tr191:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3018 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st83;
		case 42: goto st129;
	}
	goto st120;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st142;
	}
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
	}
	goto st130;
tr197:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 131;goto st612;} }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3049 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st131;
		case 32: goto st131;
		case 42: goto tr117;
		case 44: goto tr197;
		case 47: goto tr198;
		case 93: goto tr199;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st131;
	goto tr116;
tr198:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 132;goto st612;} }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3068 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st133;
		case 44: goto st73;
		case 47: goto tr201;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st131;
	}
	goto st61;
tr201:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3095 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st135;
	}
	goto st130;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st139;
	}
	goto st130;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st137;
	}
	goto st130;
tr205:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 137;goto st612;} }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 3127 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st137;
		case 10: goto st59;
		case 13: goto st137;
		case 32: goto st137;
		case 44: goto tr205;
		case 47: goto tr206;
		case 93: goto tr207;
	}
	goto tr185;
tr206:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 138;goto st612;} }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 3145 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st130;
		case 44: goto st119;
		case 47: goto tr101;
		case 93: goto tr184;
	}
	goto st64;
tr207:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st640;
tr372:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st640;
tr651:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st640;
st640:
	if ( ++p == pe )
		goto _test_eof640;
case 640:
#line 3185 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 44: goto st119;
		case 47: goto tr101;
		case 93: goto tr184;
	}
	goto st64;
tr210:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 139;goto st612;} }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 3202 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st139;
		case 10: goto st66;
		case 13: goto st139;
		case 32: goto st139;
		case 42: goto tr209;
		case 44: goto tr210;
		case 47: goto tr211;
		case 93: goto tr212;
	}
	goto tr208;
tr208:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 140;goto st612;} }
	goto st140;
tr216:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 3227 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st141;
		case 44: goto st142;
		case 47: goto tr111;
		case 93: goto tr214;
	}
	goto st65;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 10: goto st66;
		case 42: goto st141;
		case 47: goto st118;
	}
	goto st65;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 9: goto st142;
		case 10: goto st66;
		case 13: goto st142;
		case 32: goto st142;
		case 42: goto tr209;
		case 47: goto tr215;
		case 93: goto tr216;
	}
	goto tr208;
tr209:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 143;goto st612;} }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 3269 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st141;
		case 44: goto st142;
		case 47: goto tr217;
		case 93: goto tr214;
	}
	goto st65;
tr217:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 3287 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st65;
		case 44: goto st119;
		case 47: goto tr101;
		case 93: goto tr184;
	}
	goto st64;
tr770:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st641;
tr214:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st641;
tr491:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st641;
st641:
	if ( ++p == pe )
		goto _test_eof641;
case 641:
#line 3324 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st66;
		case 42: goto st141;
	}
	goto st65;
tr215:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 145;goto st612;} }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 3337 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st146;
		case 44: goto st142;
		case 47: goto tr111;
		case 93: goto tr214;
	}
	goto st65;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st147;
	}
	goto st130;
tr222:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 147;goto st612;} }
	goto st147;
tr225:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 3372 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st121;
		case 44: goto st148;
		case 47: goto tr191;
		case 93: goto tr221;
	}
	goto st120;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 9: goto st148;
		case 10: goto st83;
		case 13: goto st148;
		case 32: goto st148;
		case 42: goto tr223;
		case 47: goto tr224;
		case 93: goto tr225;
	}
	goto tr222;
tr223:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 149;goto st612;} }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 3404 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st121;
		case 44: goto st148;
		case 47: goto tr226;
		case 93: goto tr221;
	}
	goto st120;
tr226:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 3422 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st119;
		case 10: goto st59;
		case 13: goto st119;
		case 32: goto st119;
		case 42: goto tr208;
		case 47: goto tr181;
		case 93: goto tr186;
	}
	goto tr185;
tr783:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st642;
tr221:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st642;
tr504:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st642;
st642:
	if ( ++p == pe )
		goto _test_eof642;
case 642:
#line 3458 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st83;
		case 42: goto st121;
	}
	goto st120;
tr224:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 151;goto st612;} }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 3471 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st152;
		case 44: goto st148;
		case 47: goto tr191;
		case 93: goto tr221;
	}
	goto st120;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 10: goto st83;
		case 42: goto st121;
		case 47: goto st148;
	}
	goto st120;
tr111:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 3499 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st66;
		case 42: goto st154;
	}
	goto st65;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 10: goto st66;
		case 42: goto st141;
		case 47: goto st140;
	}
	goto st65;
tr211:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 155;goto st612;} }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 3522 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st156;
		case 44: goto st142;
		case 47: goto tr111;
		case 93: goto tr214;
	}
	goto st65;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st157;
	}
	goto st130;
tr233:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 157;goto st612;} }
	goto st157;
tr236:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 3557 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st157;
		case 10: goto st131;
		case 13: goto st157;
		case 32: goto st157;
		case 42: goto st136;
		case 44: goto st158;
		case 47: goto tr201;
		case 93: goto tr232;
	}
	goto st130;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 9: goto st158;
		case 10: goto st131;
		case 13: goto st158;
		case 32: goto st158;
		case 42: goto tr234;
		case 47: goto tr235;
		case 93: goto tr236;
	}
	goto tr233;
tr234:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 159;goto st612;} }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 3589 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st157;
		case 10: goto st131;
		case 13: goto st157;
		case 32: goto st157;
		case 42: goto st136;
		case 44: goto st158;
		case 47: goto tr237;
		case 93: goto tr232;
	}
	goto st130;
tr237:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 3607 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st137;
		case 10: goto st59;
		case 13: goto st137;
		case 32: goto st137;
		case 42: goto tr208;
		case 44: goto tr205;
		case 47: goto tr206;
		case 93: goto tr207;
	}
	goto tr185;
tr232:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st643;
st643:
	if ( ++p == pe )
		goto _test_eof643;
case 643:
#line 3629 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
	}
	goto st130;
tr235:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 161;goto st612;} }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 3642 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st157;
		case 10: goto st131;
		case 13: goto st157;
		case 32: goto st157;
		case 42: goto st162;
		case 44: goto st158;
		case 47: goto tr201;
		case 93: goto tr232;
	}
	goto st130;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st163;
	}
	goto st130;
tr240:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 163;goto st612;} }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 3670 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st163;
		case 10: goto st83;
		case 13: goto st163;
		case 32: goto st163;
		case 42: goto tr223;
		case 44: goto tr240;
		case 47: goto tr241;
		case 93: goto tr242;
	}
	goto tr222;
tr241:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 164;goto st612;} }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 3689 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st165;
		case 44: goto st148;
		case 47: goto tr191;
		case 93: goto tr221;
	}
	goto st120;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 10: goto st131;
		case 42: goto st136;
		case 47: goto st158;
	}
	goto st130;
tr242:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st644;
tr388:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st644;
tr667:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st644;
st644:
	if ( ++p == pe )
		goto _test_eof644;
case 644:
#line 3739 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st121;
		case 44: goto st148;
		case 47: goto tr191;
		case 93: goto tr221;
	}
	goto st120;
tr212:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st645;
tr375:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st645;
tr654:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st645;
st645:
	if ( ++p == pe )
		goto _test_eof645;
case 645:
#line 3779 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st141;
		case 44: goto st142;
		case 47: goto tr111;
		case 93: goto tr214;
	}
	goto st65;
tr199:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st646;
tr358:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st646;
tr637:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st646;
st646:
	if ( ++p == pe )
		goto _test_eof646;
case 646:
#line 3819 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st62;
		case 44: goto st73;
		case 47: goto tr114;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
tr114:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 3837 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st167;
		case 47: goto st77;
	}
	goto st61;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st66;
	}
	goto st61;
tr134:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st647;
tr341:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st647;
tr620:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st647;
st647:
	if ( ++p == pe )
		goto _test_eof647;
case 647:
#line 3880 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st44;
		case 44: goto st85;
		case 47: goto tr137;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
tr128:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 3898 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st169;
		case 47: goto st130;
	}
	goto st100;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st170;
	}
	goto st100;
tr247:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 170;goto st612;} }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 3921 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st170;
		case 10: goto st66;
		case 13: goto st170;
		case 32: goto st170;
		case 42: goto tr164;
		case 44: goto tr247;
		case 47: goto tr248;
		case 93: goto tr249;
	}
	goto tr163;
tr248:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 171;goto st612;} }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 3940 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st172;
		case 44: goto st104;
		case 47: goto tr111;
		case 93: goto tr169;
	}
	goto st47;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st173;
	}
	goto st100;
tr254:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 173;goto st612;} }
	goto st173;
tr257:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 3975 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st173;
		case 10: goto st131;
		case 13: goto st173;
		case 32: goto st173;
		case 42: goto st101;
		case 44: goto st174;
		case 47: goto tr128;
		case 93: goto tr253;
	}
	goto st100;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 9: goto st174;
		case 10: goto st73;
		case 13: goto st174;
		case 32: goto st174;
		case 42: goto tr255;
		case 47: goto tr256;
		case 93: goto tr257;
	}
	goto tr254;
tr255:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 175;goto st612;} }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 4007 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st173;
		case 10: goto st131;
		case 13: goto st173;
		case 32: goto st173;
		case 42: goto st101;
		case 44: goto st174;
		case 47: goto tr258;
		case 93: goto tr253;
	}
	goto st100;
tr258:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 4025 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st102;
		case 10: goto st59;
		case 13: goto st102;
		case 32: goto st102;
		case 42: goto tr163;
		case 44: goto tr160;
		case 47: goto tr206;
		case 93: goto tr162;
	}
	goto tr151;
tr253:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st648;
st648:
	if ( ++p == pe )
		goto _test_eof648;
case 648:
#line 4047 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
	}
	goto st100;
tr256:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 177;goto st612;} }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 4060 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st173;
		case 10: goto st131;
		case 13: goto st173;
		case 32: goto st173;
		case 42: goto st178;
		case 44: goto st174;
		case 47: goto tr128;
		case 93: goto tr253;
	}
	goto st100;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st179;
	}
	goto st100;
tr261:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 179;goto st612;} }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 4088 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st179;
		case 10: goto st83;
		case 13: goto st179;
		case 32: goto st179;
		case 42: goto tr177;
		case 44: goto tr261;
		case 47: goto tr262;
		case 93: goto tr263;
	}
	goto tr176;
tr262:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 180;goto st612;} }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 4107 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st181;
		case 44: goto st114;
		case 47: goto tr191;
		case 93: goto tr175;
	}
	goto st94;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 10: goto st73;
		case 42: goto st101;
		case 47: goto st174;
	}
	goto st100;
tr263:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st649;
tr454:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st649;
tr733:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st649;
st649:
	if ( ++p == pe )
		goto _test_eof649;
case 649:
#line 4157 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st95;
		case 44: goto st114;
		case 47: goto tr145;
		case 93: goto tr175;
	}
	goto st94;
tr249:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st650;
tr441:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st650;
tr720:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st650;
st650:
	if ( ++p == pe )
		goto _test_eof650;
case 650:
#line 4197 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st106;
		case 44: goto st104;
		case 47: goto tr168;
		case 93: goto tr169;
	}
	goto st47;
tr108:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st651;
tr320:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st651;
tr599:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 108 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st651;
st651:
	if ( ++p == pe )
		goto _test_eof651;
case 651:
#line 4237 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st51;
		case 44: goto st48;
		case 47: goto tr83;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
tr78:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 182;goto st612;} }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 4256 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st183;
		case 44: goto st48;
		case 47: goto tr168;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 42: goto st62;
		case 47: goto st84;
	}
	goto st61;
tr60:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 184;goto st612;} }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 4284 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st185;
		case 44: goto st41;
		case 47: goto tr267;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	if ( (*p) == 42 )
		goto st186;
	goto st185;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 42: goto st186;
		case 47: goto st39;
	}
	goto st185;
tr267:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 4318 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st39;
		case 42: goto st189;
		case 47: goto st198;
	}
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	if ( (*p) == 10 )
		goto st39;
	goto st188;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 10: goto st190;
		case 42: goto st568;
	}
	goto st189;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 13: goto st190;
		case 32: goto st190;
		case 42: goto tr77;
		case 47: goto tr274;
		case 93: goto tr275;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st190;
	goto tr76;
tr274:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 191;goto st612;} }
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 4362 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st192;
		case 44: goto st48;
		case 47: goto tr277;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 42: goto st194;
		case 47: goto st407;
	}
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	if ( (*p) == 42 )
		goto st194;
	goto st193;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 42: goto st194;
		case 47: goto st195;
	}
	goto st193;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 13: goto st195;
		case 32: goto st195;
		case 44: goto tr97;
		case 47: goto tr282;
		case 93: goto tr283;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st195;
	goto tr58;
tr282:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 196;goto st612;} }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4420 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st193;
		case 44: goto st41;
		case 47: goto tr284;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
tr284:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4438 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st195;
		case 42: goto st199;
	}
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	if ( (*p) == 10 )
		goto st195;
	goto st198;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 10: goto st200;
		case 42: goto st364;
	}
	goto st199;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 13: goto st200;
		case 32: goto st200;
		case 42: goto tr77;
		case 44: goto tr106;
		case 47: goto tr288;
		case 93: goto tr289;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st200;
	goto tr76;
tr288:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 201;goto st612;} }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 4482 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st202;
		case 44: goto st48;
		case 47: goto tr291;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 42: goto st194;
		case 47: goto st203;
	}
	goto st193;
tr296:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 203;goto st612;} }
	goto st203;
tr299:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 4516 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st203;
		case 32: goto st203;
		case 42: goto st194;
		case 44: goto st204;
		case 47: goto tr294;
		case 93: goto tr295;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st203;
	goto st193;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 13: goto st204;
		case 32: goto st204;
		case 42: goto tr297;
		case 47: goto tr298;
		case 93: goto tr299;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st204;
	goto tr296;
tr297:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 205;goto st612;} }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4548 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st203;
		case 32: goto st203;
		case 42: goto st194;
		case 44: goto st204;
		case 47: goto tr300;
		case 93: goto tr295;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st203;
	goto st193;
tr300:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 4566 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st195;
		case 32: goto st195;
		case 42: goto tr76;
		case 44: goto tr97;
		case 47: goto tr301;
		case 93: goto tr283;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st195;
	goto tr58;
tr301:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 207;goto st612;} }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 4585 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st208;
		case 44: goto st58;
		case 47: goto tr284;
		case 93: goto tr92;
	}
	goto st57;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 10: goto st203;
		case 42: goto st209;
	}
	goto st208;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 10: goto st203;
		case 42: goto st209;
		case 47: goto st210;
	}
	goto st208;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 9: goto st210;
		case 10: goto st195;
		case 13: goto st210;
		case 32: goto st210;
		case 44: goto tr125;
		case 47: goto tr301;
		case 93: goto tr305;
	}
	goto tr93;
tr295:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st652;
st652:
	if ( ++p == pe )
		goto _test_eof652;
case 652:
#line 4640 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st194;
	goto st193;
tr298:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 211;goto st612;} }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 4651 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st203;
		case 32: goto st203;
		case 42: goto st212;
		case 44: goto st204;
		case 47: goto tr307;
		case 93: goto tr295;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st203;
	goto st193;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st320;
	}
	goto st213;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) == 42 )
		goto st214;
	goto st213;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st215;
	}
	goto st213;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 13: goto st215;
		case 32: goto st215;
		case 44: goto tr97;
		case 47: goto tr312;
		case 93: goto tr313;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st215;
	goto tr58;
tr312:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 216;goto st612;} }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 4709 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st213;
		case 44: goto st41;
		case 47: goto tr314;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
tr314:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st217;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
#line 4727 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st215;
		case 42: goto st219;
	}
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	if ( (*p) == 10 )
		goto st215;
	goto st218;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 10: goto st220;
		case 42: goto st270;
	}
	goto st219;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 13: goto st220;
		case 32: goto st220;
		case 42: goto tr77;
		case 44: goto tr106;
		case 47: goto tr319;
		case 93: goto tr320;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st220;
	goto tr76;
tr319:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 221;goto st612;} }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 4771 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st222;
		case 44: goto st48;
		case 47: goto tr322;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st223;
	}
	goto st213;
tr327:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 223;goto st612;} }
	goto st223;
tr330:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 4805 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st223;
		case 32: goto st223;
		case 42: goto st214;
		case 44: goto st224;
		case 47: goto tr325;
		case 93: goto tr326;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st223;
	goto st213;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 13: goto st224;
		case 32: goto st224;
		case 42: goto tr328;
		case 47: goto tr329;
		case 93: goto tr330;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st224;
	goto tr327;
tr328:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 225;goto st612;} }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 4837 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st223;
		case 32: goto st223;
		case 42: goto st214;
		case 44: goto st224;
		case 47: goto tr331;
		case 93: goto tr326;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st223;
	goto st213;
tr331:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 4855 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st215;
		case 32: goto st215;
		case 42: goto tr76;
		case 44: goto tr97;
		case 47: goto tr332;
		case 93: goto tr313;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st215;
	goto tr58;
tr332:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 227;goto st612;} }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 4874 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st228;
		case 44: goto st58;
		case 47: goto tr314;
		case 93: goto tr92;
	}
	goto st57;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 10: goto st223;
		case 42: goto st229;
	}
	goto st228;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 10: goto st223;
		case 42: goto st229;
		case 47: goto st230;
	}
	goto st228;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 9: goto st230;
		case 10: goto st215;
		case 13: goto st230;
		case 32: goto st230;
		case 44: goto tr125;
		case 47: goto tr332;
		case 93: goto tr336;
	}
	goto tr93;
tr326:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st653;
st653:
	if ( ++p == pe )
		goto _test_eof653;
case 653:
#line 4929 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st214;
	goto st213;
tr329:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 231;goto st612;} }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 4940 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st223;
		case 32: goto st223;
		case 42: goto st232;
		case 44: goto st224;
		case 47: goto tr338;
		case 93: goto tr326;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st223;
	goto st213;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st233;
	}
	goto st213;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 13: goto st233;
		case 32: goto st233;
		case 42: goto tr131;
		case 44: goto tr132;
		case 47: goto tr340;
		case 93: goto tr341;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st233;
	goto tr130;
tr340:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 234;goto st612;} }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 4983 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st235;
		case 44: goto st85;
		case 47: goto tr343;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st224;
	}
	goto st213;
tr343:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 5010 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st233;
		case 42: goto st242;
	}
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 10: goto st233;
		case 42: goto st238;
	}
	goto st237;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	switch( (*p) ) {
		case 10: goto st233;
		case 42: goto st238;
		case 47: goto st239;
	}
	goto st237;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 9: goto st239;
		case 10: goto st215;
		case 13: goto st239;
		case 32: goto st239;
		case 47: goto tr349;
		case 93: goto tr350;
	}
	goto tr348;
tr348:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 240;goto st612;} }
	goto st240;
tr350:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 5061 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st240;
		case 10: goto st215;
		case 13: goto st240;
		case 32: goto st240;
		case 44: goto st239;
		case 47: goto tr314;
		case 93: goto tr352;
	}
	goto st218;
tr352:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st654;
st654:
	if ( ++p == pe )
		goto _test_eof654;
case 654:
#line 5082 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st215;
	goto st218;
tr349:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 241;goto st612;} }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 5093 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st240;
		case 10: goto st215;
		case 13: goto st240;
		case 32: goto st240;
		case 42: goto st237;
		case 44: goto st239;
		case 47: goto tr314;
		case 93: goto tr352;
	}
	goto st218;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st272;
	}
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
	}
	goto st243;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	switch( (*p) ) {
		case 13: goto st244;
		case 32: goto st244;
		case 42: goto tr117;
		case 44: goto tr197;
		case 47: goto tr357;
		case 93: goto tr358;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st244;
	goto tr116;
tr357:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 245;goto st612;} }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 5146 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st246;
		case 44: goto st73;
		case 47: goto tr360;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st247;
	}
	goto st213;
tr362:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 247;goto st612;} }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 5173 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st247;
		case 32: goto st247;
		case 42: goto tr328;
		case 44: goto tr362;
		case 47: goto tr363;
		case 93: goto tr364;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st247;
	goto tr327;
tr363:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 248;goto st612;} }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 5192 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st223;
		case 32: goto st223;
		case 42: goto st249;
		case 44: goto st224;
		case 47: goto tr366;
		case 93: goto tr326;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st223;
	goto st213;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st244;
	}
	goto st213;
tr366:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 5219 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st255;
	}
	goto st251;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
	}
	goto st251;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st253;
	}
	goto st251;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	switch( (*p) ) {
		case 9: goto st253;
		case 10: goto st215;
		case 13: goto st253;
		case 32: goto st253;
		case 44: goto tr205;
		case 47: goto tr371;
		case 93: goto tr372;
	}
	goto tr185;
tr371:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 254;goto st612;} }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 5265 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st251;
		case 44: goto st119;
		case 47: goto tr314;
		case 93: goto tr184;
	}
	goto st64;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st256;
	}
	goto st251;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	switch( (*p) ) {
		case 9: goto st256;
		case 10: goto st220;
		case 13: goto st256;
		case 32: goto st256;
		case 42: goto tr209;
		case 44: goto tr210;
		case 47: goto tr374;
		case 93: goto tr375;
	}
	goto tr208;
tr374:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 257;goto st612;} }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 5309 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st258;
		case 44: goto st142;
		case 47: goto tr322;
		case 93: goto tr214;
	}
	goto st65;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st259;
	}
	goto st251;
tr380:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 259;goto st612;} }
	goto st259;
tr383:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 5344 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st259;
		case 10: goto st247;
		case 13: goto st259;
		case 32: goto st259;
		case 42: goto st252;
		case 44: goto st260;
		case 47: goto tr366;
		case 93: goto tr379;
	}
	goto st251;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	switch( (*p) ) {
		case 9: goto st260;
		case 10: goto st247;
		case 13: goto st260;
		case 32: goto st260;
		case 42: goto tr381;
		case 47: goto tr382;
		case 93: goto tr383;
	}
	goto tr380;
tr381:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 261;goto st612;} }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 5376 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st259;
		case 10: goto st247;
		case 13: goto st259;
		case 32: goto st259;
		case 42: goto st252;
		case 44: goto st260;
		case 47: goto tr384;
		case 93: goto tr379;
	}
	goto st251;
tr384:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st262;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
#line 5394 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st253;
		case 10: goto st215;
		case 13: goto st253;
		case 32: goto st253;
		case 42: goto tr208;
		case 44: goto tr205;
		case 47: goto tr371;
		case 93: goto tr372;
	}
	goto tr185;
tr379:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st655;
st655:
	if ( ++p == pe )
		goto _test_eof655;
case 655:
#line 5416 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
	}
	goto st251;
tr382:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 263;goto st612;} }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 5429 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st259;
		case 10: goto st247;
		case 13: goto st259;
		case 32: goto st259;
		case 42: goto st264;
		case 44: goto st260;
		case 47: goto tr366;
		case 93: goto tr379;
	}
	goto st251;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st265;
	}
	goto st251;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 9: goto st265;
		case 10: goto st233;
		case 13: goto st265;
		case 32: goto st265;
		case 42: goto tr223;
		case 44: goto tr240;
		case 47: goto tr387;
		case 93: goto tr388;
	}
	goto tr222;
tr387:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 266;goto st612;} }
	goto st266;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
#line 5473 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st267;
		case 44: goto st148;
		case 47: goto tr343;
		case 93: goto tr221;
	}
	goto st120;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st260;
	}
	goto st251;
tr322:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 5501 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st220;
		case 42: goto st269;
	}
	goto st219;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 10: goto st220;
		case 42: goto st270;
		case 47: goto st271;
	}
	goto st219;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	switch( (*p) ) {
		case 10: goto st220;
		case 42: goto st270;
		case 47: goto st240;
	}
	goto st219;
tr393:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 271;goto st612;} }
	goto st271;
tr396:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 5540 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto st220;
		case 13: goto st271;
		case 32: goto st271;
		case 42: goto st270;
		case 44: goto st272;
		case 47: goto tr322;
		case 93: goto tr392;
	}
	goto st219;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	switch( (*p) ) {
		case 9: goto st272;
		case 10: goto st220;
		case 13: goto st272;
		case 32: goto st272;
		case 42: goto tr394;
		case 47: goto tr395;
		case 93: goto tr396;
	}
	goto tr393;
tr394:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 273;goto st612;} }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 5572 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto st220;
		case 13: goto st271;
		case 32: goto st271;
		case 42: goto st270;
		case 44: goto st272;
		case 47: goto tr397;
		case 93: goto tr392;
	}
	goto st219;
tr397:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 5590 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st240;
		case 10: goto st215;
		case 13: goto st240;
		case 32: goto st240;
		case 42: goto st219;
		case 44: goto st239;
		case 47: goto tr314;
		case 93: goto tr352;
	}
	goto st218;
tr392:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st656;
st656:
	if ( ++p == pe )
		goto _test_eof656;
case 656:
#line 5612 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st220;
		case 42: goto st270;
	}
	goto st219;
tr395:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 275;goto st612;} }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 5625 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto st220;
		case 13: goto st271;
		case 32: goto st271;
		case 42: goto st276;
		case 44: goto st272;
		case 47: goto tr322;
		case 93: goto tr392;
	}
	goto st219;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st280;
	}
	goto st243;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st278;
	}
	goto st243;
tr401:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 278;goto st612;} }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 5663 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st278;
		case 10: goto st215;
		case 13: goto st278;
		case 32: goto st278;
		case 44: goto tr401;
		case 47: goto tr402;
		case 93: goto tr403;
	}
	goto tr348;
tr402:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 279;goto st612;} }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 5681 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st240;
		case 10: goto st215;
		case 13: goto st240;
		case 32: goto st240;
		case 42: goto st243;
		case 44: goto st239;
		case 47: goto tr314;
		case 93: goto tr352;
	}
	goto st218;
tr403:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st657;
st657:
	if ( ++p == pe )
		goto _test_eof657;
case 657:
#line 5704 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st240;
		case 10: goto st215;
		case 13: goto st240;
		case 32: goto st240;
		case 44: goto st239;
		case 47: goto tr314;
		case 93: goto tr352;
	}
	goto st218;
tr406:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 280;goto st612;} }
	goto st280;
tr409:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 5728 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st280;
		case 10: goto st233;
		case 13: goto st280;
		case 32: goto st280;
		case 42: goto st238;
		case 44: goto st281;
		case 47: goto tr343;
		case 93: goto tr405;
	}
	goto st237;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	switch( (*p) ) {
		case 9: goto st281;
		case 10: goto st233;
		case 13: goto st281;
		case 32: goto st281;
		case 42: goto tr407;
		case 47: goto tr408;
		case 93: goto tr409;
	}
	goto tr406;
tr407:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 282;goto st612;} }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 5760 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st280;
		case 10: goto st233;
		case 13: goto st280;
		case 32: goto st280;
		case 42: goto st238;
		case 44: goto st281;
		case 47: goto tr410;
		case 93: goto tr405;
	}
	goto st237;
tr410:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 5778 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st239;
		case 10: goto st215;
		case 13: goto st239;
		case 32: goto st239;
		case 42: goto tr393;
		case 47: goto tr349;
		case 93: goto tr350;
	}
	goto tr348;
tr405:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st658;
st658:
	if ( ++p == pe )
		goto _test_eof658;
case 658:
#line 5799 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st233;
		case 42: goto st238;
	}
	goto st237;
tr408:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 284;goto st612;} }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 5812 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st280;
		case 10: goto st233;
		case 13: goto st280;
		case 32: goto st280;
		case 42: goto st285;
		case 44: goto st281;
		case 47: goto tr343;
		case 93: goto tr405;
	}
	goto st237;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	switch( (*p) ) {
		case 10: goto st233;
		case 42: goto st238;
		case 47: goto st281;
	}
	goto st237;
tr364:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st659;
st659:
	if ( ++p == pe )
		goto _test_eof659;
case 659:
#line 5845 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st223;
		case 32: goto st223;
		case 42: goto st214;
		case 44: goto st224;
		case 47: goto tr325;
		case 93: goto tr326;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st223;
	goto st213;
tr325:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 5863 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st287;
		case 47: goto st228;
	}
	goto st213;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st220;
	}
	goto st213;
tr360:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 5884 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st289;
	}
	goto st243;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st290;
	}
	goto st243;
tr415:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 290;goto st612;} }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 5906 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st290;
		case 10: goto st220;
		case 13: goto st290;
		case 32: goto st290;
		case 42: goto tr394;
		case 44: goto tr415;
		case 47: goto tr416;
		case 93: goto tr417;
	}
	goto tr393;
tr416:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 291;goto st612;} }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 5925 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto st220;
		case 13: goto st271;
		case 32: goto st271;
		case 42: goto st292;
		case 44: goto st272;
		case 47: goto tr322;
		case 93: goto tr392;
	}
	goto st219;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st293;
	}
	goto st243;
tr422:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 293;goto st612;} }
	goto st293;
tr425:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 5960 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st293;
		case 10: goto st244;
		case 13: goto st293;
		case 32: goto st293;
		case 42: goto st277;
		case 44: goto st294;
		case 47: goto tr360;
		case 93: goto tr421;
	}
	goto st243;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	switch( (*p) ) {
		case 9: goto st294;
		case 10: goto st244;
		case 13: goto st294;
		case 32: goto st294;
		case 42: goto tr423;
		case 47: goto tr424;
		case 93: goto tr425;
	}
	goto tr422;
tr423:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 295;goto st612;} }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 5992 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st293;
		case 10: goto st244;
		case 13: goto st293;
		case 32: goto st293;
		case 42: goto st277;
		case 44: goto st294;
		case 47: goto tr426;
		case 93: goto tr421;
	}
	goto st243;
tr426:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st296;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
#line 6010 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st278;
		case 10: goto st215;
		case 13: goto st278;
		case 32: goto st278;
		case 42: goto tr393;
		case 44: goto tr401;
		case 47: goto tr402;
		case 93: goto tr403;
	}
	goto tr348;
tr421:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st660;
st660:
	if ( ++p == pe )
		goto _test_eof660;
case 660:
#line 6032 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
	}
	goto st243;
tr424:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 297;goto st612;} }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 6045 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st293;
		case 10: goto st244;
		case 13: goto st293;
		case 32: goto st293;
		case 42: goto st298;
		case 44: goto st294;
		case 47: goto tr360;
		case 93: goto tr421;
	}
	goto st243;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st299;
	}
	goto st243;
tr429:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 299;goto st612;} }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 6073 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st299;
		case 10: goto st233;
		case 13: goto st299;
		case 32: goto st299;
		case 42: goto tr407;
		case 44: goto tr429;
		case 47: goto tr430;
		case 93: goto tr431;
	}
	goto tr406;
tr430:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 300;goto st612;} }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 6092 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st280;
		case 10: goto st233;
		case 13: goto st280;
		case 32: goto st280;
		case 42: goto st301;
		case 44: goto st281;
		case 47: goto tr343;
		case 93: goto tr405;
	}
	goto st237;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	switch( (*p) ) {
		case 10: goto st244;
		case 42: goto st277;
		case 47: goto st294;
	}
	goto st243;
tr431:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st661;
st661:
	if ( ++p == pe )
		goto _test_eof661;
case 661:
#line 6125 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st280;
		case 10: goto st233;
		case 13: goto st280;
		case 32: goto st280;
		case 42: goto st238;
		case 44: goto st281;
		case 47: goto tr343;
		case 93: goto tr405;
	}
	goto st237;
tr417:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st662;
st662:
	if ( ++p == pe )
		goto _test_eof662;
case 662:
#line 6148 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st271;
		case 10: goto st220;
		case 13: goto st271;
		case 32: goto st271;
		case 42: goto st270;
		case 44: goto st272;
		case 47: goto tr322;
		case 93: goto tr392;
	}
	goto st219;
tr338:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 6166 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st307;
		case 47: goto st251;
	}
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
	}
	goto st303;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st305;
	}
	goto st303;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	switch( (*p) ) {
		case 9: goto st305;
		case 10: goto st215;
		case 13: goto st305;
		case 32: goto st305;
		case 44: goto tr160;
		case 47: goto tr437;
		case 93: goto tr438;
	}
	goto tr151;
tr437:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 306;goto st612;} }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 6213 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st303;
		case 44: goto st96;
		case 47: goto tr314;
		case 93: goto tr155;
	}
	goto st46;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st308;
	}
	goto st303;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	switch( (*p) ) {
		case 9: goto st308;
		case 10: goto st220;
		case 13: goto st308;
		case 32: goto st308;
		case 42: goto tr164;
		case 44: goto tr247;
		case 47: goto tr440;
		case 93: goto tr441;
	}
	goto tr163;
tr440:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 309;goto st612;} }
	goto st309;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
#line 6257 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st310;
		case 44: goto st104;
		case 47: goto tr322;
		case 93: goto tr169;
	}
	goto st47;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st311;
	}
	goto st303;
tr446:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 311;goto st612;} }
	goto st311;
tr449:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 6292 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st311;
		case 10: goto st247;
		case 13: goto st311;
		case 32: goto st311;
		case 42: goto st304;
		case 44: goto st312;
		case 47: goto tr338;
		case 93: goto tr445;
	}
	goto st303;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 9: goto st312;
		case 10: goto st224;
		case 13: goto st312;
		case 32: goto st312;
		case 42: goto tr447;
		case 47: goto tr448;
		case 93: goto tr449;
	}
	goto tr446;
tr447:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 313;goto st612;} }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 6324 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st311;
		case 10: goto st247;
		case 13: goto st311;
		case 32: goto st311;
		case 42: goto st304;
		case 44: goto st312;
		case 47: goto tr450;
		case 93: goto tr445;
	}
	goto st303;
tr450:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 6342 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st305;
		case 10: goto st215;
		case 13: goto st305;
		case 32: goto st305;
		case 42: goto tr163;
		case 44: goto tr160;
		case 47: goto tr371;
		case 93: goto tr438;
	}
	goto tr151;
tr445:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st663;
st663:
	if ( ++p == pe )
		goto _test_eof663;
case 663:
#line 6364 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
	}
	goto st303;
tr448:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 315;goto st612;} }
	goto st315;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
#line 6377 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st311;
		case 10: goto st247;
		case 13: goto st311;
		case 32: goto st311;
		case 42: goto st316;
		case 44: goto st312;
		case 47: goto tr338;
		case 93: goto tr445;
	}
	goto st303;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st317;
	}
	goto st303;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	switch( (*p) ) {
		case 9: goto st317;
		case 10: goto st233;
		case 13: goto st317;
		case 32: goto st317;
		case 42: goto tr177;
		case 44: goto tr261;
		case 47: goto tr453;
		case 93: goto tr454;
	}
	goto tr176;
tr453:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 318;goto st612;} }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 6421 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st319;
		case 44: goto st114;
		case 47: goto tr343;
		case 93: goto tr175;
	}
	goto st94;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st312;
	}
	goto st303;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	switch( (*p) ) {
		case 13: goto st320;
		case 32: goto st320;
		case 42: goto tr131;
		case 44: goto tr132;
		case 47: goto tr456;
		case 93: goto tr457;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st320;
	goto tr130;
tr456:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 321;goto st612;} }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 6465 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st322;
		case 44: goto st85;
		case 47: goto tr459;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st204;
	}
	goto st213;
tr459:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 6492 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st320;
		case 42: goto st329;
	}
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 10: goto st320;
		case 42: goto st325;
	}
	goto st324;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 10: goto st320;
		case 42: goto st325;
		case 47: goto st326;
	}
	goto st324;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	switch( (*p) ) {
		case 9: goto st326;
		case 10: goto st215;
		case 13: goto st326;
		case 32: goto st326;
		case 47: goto tr465;
		case 93: goto tr466;
	}
	goto tr464;
tr464:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 327;goto st612;} }
	goto st327;
tr466:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 6543 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st327;
		case 10: goto st195;
		case 13: goto st327;
		case 32: goto st327;
		case 44: goto st326;
		case 47: goto tr284;
		case 93: goto tr468;
	}
	goto st198;
tr468:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st664;
st664:
	if ( ++p == pe )
		goto _test_eof664;
case 664:
#line 6564 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st195;
	goto st198;
tr465:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 328;goto st612;} }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 6575 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st327;
		case 10: goto st195;
		case 13: goto st327;
		case 32: goto st327;
		case 42: goto st324;
		case 44: goto st326;
		case 47: goto tr314;
		case 93: goto tr468;
	}
	goto st198;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st365;
	}
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
	}
	goto st330;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	switch( (*p) ) {
		case 13: goto st331;
		case 32: goto st331;
		case 42: goto tr117;
		case 44: goto tr197;
		case 47: goto tr473;
		case 93: goto tr474;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st331;
	goto tr116;
tr473:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 332;goto st612;} }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 6628 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st333;
		case 44: goto st73;
		case 47: goto tr476;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st334;
	}
	goto st213;
tr478:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 334;goto st612;} }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 6655 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st334;
		case 32: goto st334;
		case 42: goto tr297;
		case 44: goto tr478;
		case 47: goto tr479;
		case 93: goto tr480;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st334;
	goto tr296;
tr479:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 335;goto st612;} }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 6674 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st203;
		case 32: goto st203;
		case 42: goto st336;
		case 44: goto st204;
		case 47: goto tr482;
		case 93: goto tr295;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st203;
	goto st193;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st331;
	}
	goto st213;
tr482:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 6701 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st342;
	}
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
	}
	goto st338;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
		case 47: goto st340;
	}
	goto st338;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 9: goto st340;
		case 10: goto st215;
		case 13: goto st340;
		case 32: goto st340;
		case 44: goto tr205;
		case 47: goto tr487;
		case 93: goto tr488;
	}
	goto tr185;
tr487:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 341;goto st612;} }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 6747 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st338;
		case 44: goto st119;
		case 47: goto tr314;
		case 93: goto tr184;
	}
	goto st64;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
		case 47: goto st343;
	}
	goto st338;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	switch( (*p) ) {
		case 9: goto st343;
		case 10: goto st220;
		case 13: goto st343;
		case 32: goto st343;
		case 42: goto tr209;
		case 44: goto tr210;
		case 47: goto tr490;
		case 93: goto tr491;
	}
	goto tr208;
tr490:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 344;goto st612;} }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 6791 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st345;
		case 44: goto st142;
		case 47: goto tr322;
		case 93: goto tr214;
	}
	goto st65;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
		case 47: goto st346;
	}
	goto st338;
tr496:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 346;goto st612;} }
	goto st346;
tr499:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 6826 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st346;
		case 10: goto st334;
		case 13: goto st346;
		case 32: goto st346;
		case 42: goto st339;
		case 44: goto st347;
		case 47: goto tr482;
		case 93: goto tr495;
	}
	goto st338;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	switch( (*p) ) {
		case 9: goto st347;
		case 10: goto st334;
		case 13: goto st347;
		case 32: goto st347;
		case 42: goto tr497;
		case 47: goto tr498;
		case 93: goto tr499;
	}
	goto tr496;
tr497:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 348;goto st612;} }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 6858 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st346;
		case 10: goto st334;
		case 13: goto st346;
		case 32: goto st346;
		case 42: goto st339;
		case 44: goto st347;
		case 47: goto tr500;
		case 93: goto tr495;
	}
	goto st338;
tr500:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st349;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
#line 6876 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st340;
		case 10: goto st215;
		case 13: goto st340;
		case 32: goto st340;
		case 42: goto tr208;
		case 44: goto tr205;
		case 47: goto tr487;
		case 93: goto tr488;
	}
	goto tr185;
tr495:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st665;
st665:
	if ( ++p == pe )
		goto _test_eof665;
case 665:
#line 6898 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
	}
	goto st338;
tr498:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 350;goto st612;} }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 6911 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st346;
		case 10: goto st334;
		case 13: goto st346;
		case 32: goto st346;
		case 42: goto st351;
		case 44: goto st347;
		case 47: goto tr482;
		case 93: goto tr495;
	}
	goto st338;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st352;
	}
	goto st251;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	switch( (*p) ) {
		case 9: goto st352;
		case 10: goto st233;
		case 13: goto st352;
		case 32: goto st352;
		case 42: goto tr223;
		case 44: goto tr240;
		case 47: goto tr503;
		case 93: goto tr504;
	}
	goto tr222;
tr503:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 353;goto st612;} }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 6955 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st354;
		case 44: goto st148;
		case 47: goto tr343;
		case 93: goto tr221;
	}
	goto st120;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st347;
	}
	goto st251;
tr480:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st666;
st666:
	if ( ++p == pe )
		goto _test_eof666;
case 666:
#line 6988 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st203;
		case 32: goto st203;
		case 42: goto st194;
		case 44: goto st204;
		case 47: goto tr294;
		case 93: goto tr295;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st203;
	goto st193;
tr294:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st355;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
#line 7006 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st356;
		case 47: goto st208;
	}
	goto st193;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	switch( (*p) ) {
		case 42: goto st194;
		case 47: goto st200;
	}
	goto st193;
tr476:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 7027 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st358;
	}
	goto st330;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st362;
	}
	goto st330;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st360;
	}
	goto st330;
tr510:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 360;goto st612;} }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 7059 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st360;
		case 10: goto st215;
		case 13: goto st360;
		case 32: goto st360;
		case 44: goto tr510;
		case 47: goto tr511;
		case 93: goto tr512;
	}
	goto tr464;
tr511:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 361;goto st612;} }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 7077 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st327;
		case 10: goto st195;
		case 13: goto st327;
		case 32: goto st327;
		case 42: goto st330;
		case 44: goto st326;
		case 47: goto tr314;
		case 93: goto tr468;
	}
	goto st198;
tr512:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st667;
st667:
	if ( ++p == pe )
		goto _test_eof667;
case 667:
#line 7100 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st327;
		case 10: goto st195;
		case 13: goto st327;
		case 32: goto st327;
		case 44: goto st326;
		case 47: goto tr284;
		case 93: goto tr468;
	}
	goto st198;
tr515:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 362;goto st612;} }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 7117 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st362;
		case 10: goto st220;
		case 13: goto st362;
		case 32: goto st362;
		case 42: goto tr514;
		case 44: goto tr515;
		case 47: goto tr516;
		case 93: goto tr517;
	}
	goto tr513;
tr513:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 363;goto st612;} }
	goto st363;
tr521:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 7142 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st363;
		case 10: goto st200;
		case 13: goto st363;
		case 32: goto st363;
		case 42: goto st364;
		case 44: goto st365;
		case 47: goto tr291;
		case 93: goto tr519;
	}
	goto st199;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	switch( (*p) ) {
		case 10: goto st200;
		case 42: goto st364;
		case 47: goto st327;
	}
	goto st199;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	switch( (*p) ) {
		case 9: goto st365;
		case 10: goto st220;
		case 13: goto st365;
		case 32: goto st365;
		case 42: goto tr514;
		case 47: goto tr520;
		case 93: goto tr521;
	}
	goto tr513;
tr514:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 366;goto st612;} }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 7184 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st363;
		case 10: goto st200;
		case 13: goto st363;
		case 32: goto st363;
		case 42: goto st364;
		case 44: goto st365;
		case 47: goto tr522;
		case 93: goto tr519;
	}
	goto st199;
tr522:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 7202 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st327;
		case 10: goto st195;
		case 13: goto st327;
		case 32: goto st327;
		case 42: goto st199;
		case 44: goto st326;
		case 47: goto tr284;
		case 93: goto tr468;
	}
	goto st198;
tr519:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st668;
st668:
	if ( ++p == pe )
		goto _test_eof668;
case 668:
#line 7224 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st200;
		case 42: goto st364;
	}
	goto st199;
tr520:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 368;goto st612;} }
	goto st368;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
#line 7237 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st363;
		case 10: goto st200;
		case 13: goto st363;
		case 32: goto st363;
		case 42: goto st369;
		case 44: goto st365;
		case 47: goto tr322;
		case 93: goto tr519;
	}
	goto st199;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st370;
	}
	goto st330;
tr527:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 370;goto st612;} }
	goto st370;
tr530:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st370;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
#line 7272 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st370;
		case 10: goto st320;
		case 13: goto st370;
		case 32: goto st370;
		case 42: goto st325;
		case 44: goto st371;
		case 47: goto tr459;
		case 93: goto tr526;
	}
	goto st324;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 9: goto st371;
		case 10: goto st233;
		case 13: goto st371;
		case 32: goto st371;
		case 42: goto tr528;
		case 47: goto tr529;
		case 93: goto tr530;
	}
	goto tr527;
tr528:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 372;goto st612;} }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 7304 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st370;
		case 10: goto st320;
		case 13: goto st370;
		case 32: goto st370;
		case 42: goto st325;
		case 44: goto st371;
		case 47: goto tr531;
		case 93: goto tr526;
	}
	goto st324;
tr531:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 7322 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st326;
		case 10: goto st215;
		case 13: goto st326;
		case 32: goto st326;
		case 42: goto tr513;
		case 47: goto tr465;
		case 93: goto tr466;
	}
	goto tr464;
tr526:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st669;
st669:
	if ( ++p == pe )
		goto _test_eof669;
case 669:
#line 7343 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st320;
		case 42: goto st325;
	}
	goto st324;
tr529:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 374;goto st612;} }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 7356 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st370;
		case 10: goto st320;
		case 13: goto st370;
		case 32: goto st370;
		case 42: goto st375;
		case 44: goto st371;
		case 47: goto tr343;
		case 93: goto tr526;
	}
	goto st324;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 10: goto st320;
		case 42: goto st325;
		case 47: goto st371;
	}
	goto st324;
tr291:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 7384 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st200;
		case 42: goto st377;
	}
	goto st199;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 10: goto st200;
		case 42: goto st364;
		case 47: goto st363;
	}
	goto st199;
tr516:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 378;goto st612;} }
	goto st378;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
#line 7407 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st363;
		case 10: goto st200;
		case 13: goto st363;
		case 32: goto st363;
		case 42: goto st379;
		case 44: goto st365;
		case 47: goto tr322;
		case 93: goto tr519;
	}
	goto st199;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st380;
	}
	goto st330;
tr538:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 380;goto st612;} }
	goto st380;
tr541:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 7442 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st380;
		case 10: goto st331;
		case 13: goto st380;
		case 32: goto st380;
		case 42: goto st359;
		case 44: goto st381;
		case 47: goto tr476;
		case 93: goto tr537;
	}
	goto st330;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	switch( (*p) ) {
		case 9: goto st381;
		case 10: goto st244;
		case 13: goto st381;
		case 32: goto st381;
		case 42: goto tr539;
		case 47: goto tr540;
		case 93: goto tr541;
	}
	goto tr538;
tr539:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 382;goto st612;} }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 7474 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st380;
		case 10: goto st331;
		case 13: goto st380;
		case 32: goto st380;
		case 42: goto st359;
		case 44: goto st381;
		case 47: goto tr542;
		case 93: goto tr537;
	}
	goto st330;
tr542:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 7492 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st360;
		case 10: goto st215;
		case 13: goto st360;
		case 32: goto st360;
		case 42: goto tr513;
		case 44: goto tr510;
		case 47: goto tr511;
		case 93: goto tr512;
	}
	goto tr464;
tr537:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st670;
st670:
	if ( ++p == pe )
		goto _test_eof670;
case 670:
#line 7514 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
	}
	goto st330;
tr540:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 384;goto st612;} }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 7527 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st380;
		case 10: goto st331;
		case 13: goto st380;
		case 32: goto st380;
		case 42: goto st385;
		case 44: goto st381;
		case 47: goto tr360;
		case 93: goto tr537;
	}
	goto st330;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st386;
	}
	goto st330;
tr545:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 386;goto st612;} }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 7555 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st386;
		case 10: goto st233;
		case 13: goto st386;
		case 32: goto st386;
		case 42: goto tr528;
		case 44: goto tr545;
		case 47: goto tr546;
		case 93: goto tr547;
	}
	goto tr527;
tr546:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 387;goto st612;} }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 7574 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st370;
		case 10: goto st320;
		case 13: goto st370;
		case 32: goto st370;
		case 42: goto st388;
		case 44: goto st371;
		case 47: goto tr343;
		case 93: goto tr526;
	}
	goto st324;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	switch( (*p) ) {
		case 10: goto st331;
		case 42: goto st359;
		case 47: goto st381;
	}
	goto st330;
tr547:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st671;
st671:
	if ( ++p == pe )
		goto _test_eof671;
case 671:
#line 7607 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st370;
		case 10: goto st320;
		case 13: goto st370;
		case 32: goto st370;
		case 42: goto st325;
		case 44: goto st371;
		case 47: goto tr459;
		case 93: goto tr526;
	}
	goto st324;
tr517:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st672;
st672:
	if ( ++p == pe )
		goto _test_eof672;
case 672:
#line 7630 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st363;
		case 10: goto st200;
		case 13: goto st363;
		case 32: goto st363;
		case 42: goto st364;
		case 44: goto st365;
		case 47: goto tr291;
		case 93: goto tr519;
	}
	goto st199;
tr307:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 7648 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st394;
		case 47: goto st338;
	}
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
	}
	goto st390;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
		case 47: goto st392;
	}
	goto st390;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	switch( (*p) ) {
		case 9: goto st392;
		case 10: goto st215;
		case 13: goto st392;
		case 32: goto st392;
		case 44: goto tr160;
		case 47: goto tr553;
		case 93: goto tr554;
	}
	goto tr151;
tr553:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 393;goto st612;} }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 7695 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st390;
		case 44: goto st96;
		case 47: goto tr314;
		case 93: goto tr155;
	}
	goto st46;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
		case 47: goto st395;
	}
	goto st390;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	switch( (*p) ) {
		case 9: goto st395;
		case 10: goto st220;
		case 13: goto st395;
		case 32: goto st395;
		case 42: goto tr164;
		case 44: goto tr247;
		case 47: goto tr556;
		case 93: goto tr557;
	}
	goto tr163;
tr556:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 396;goto st612;} }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 7739 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st397;
		case 44: goto st104;
		case 47: goto tr322;
		case 93: goto tr169;
	}
	goto st47;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
		case 47: goto st398;
	}
	goto st390;
tr562:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 398;goto st612;} }
	goto st398;
tr565:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 7774 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st398;
		case 10: goto st334;
		case 13: goto st398;
		case 32: goto st398;
		case 42: goto st391;
		case 44: goto st399;
		case 47: goto tr307;
		case 93: goto tr561;
	}
	goto st390;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	switch( (*p) ) {
		case 9: goto st399;
		case 10: goto st204;
		case 13: goto st399;
		case 32: goto st399;
		case 42: goto tr563;
		case 47: goto tr564;
		case 93: goto tr565;
	}
	goto tr562;
tr563:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 400;goto st612;} }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 7806 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st398;
		case 10: goto st334;
		case 13: goto st398;
		case 32: goto st398;
		case 42: goto st391;
		case 44: goto st399;
		case 47: goto tr566;
		case 93: goto tr561;
	}
	goto st390;
tr566:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 7824 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st392;
		case 10: goto st215;
		case 13: goto st392;
		case 32: goto st392;
		case 42: goto tr163;
		case 44: goto tr160;
		case 47: goto tr487;
		case 93: goto tr554;
	}
	goto tr151;
tr561:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st673;
st673:
	if ( ++p == pe )
		goto _test_eof673;
case 673:
#line 7846 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
	}
	goto st390;
tr564:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 402;goto st612;} }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 7859 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st398;
		case 10: goto st334;
		case 13: goto st398;
		case 32: goto st398;
		case 42: goto st403;
		case 44: goto st399;
		case 47: goto tr307;
		case 93: goto tr561;
	}
	goto st390;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st404;
	}
	goto st303;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	switch( (*p) ) {
		case 9: goto st404;
		case 10: goto st233;
		case 13: goto st404;
		case 32: goto st404;
		case 42: goto tr177;
		case 44: goto tr261;
		case 47: goto tr569;
		case 93: goto tr570;
	}
	goto tr176;
tr569:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 405;goto st612;} }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 7903 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st406;
		case 44: goto st114;
		case 47: goto tr343;
		case 93: goto tr175;
	}
	goto st94;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st399;
	}
	goto st303;
tr575:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 407;goto st612;} }
	goto st407;
tr578:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 7938 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st407;
		case 32: goto st407;
		case 42: goto st186;
		case 44: goto st408;
		case 47: goto tr573;
		case 93: goto tr574;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st407;
	goto st185;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	switch( (*p) ) {
		case 13: goto st408;
		case 32: goto st408;
		case 42: goto tr576;
		case 47: goto tr577;
		case 93: goto tr578;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st408;
	goto tr575;
tr576:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 409;goto st612;} }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 7970 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st407;
		case 32: goto st407;
		case 42: goto st186;
		case 44: goto st408;
		case 47: goto tr579;
		case 93: goto tr574;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st407;
	goto st185;
tr579:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 7988 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st39;
		case 32: goto st39;
		case 42: goto tr76;
		case 47: goto tr580;
		case 93: goto tr61;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st39;
	goto tr58;
tr580:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 411;goto st612;} }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 8006 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st412;
		case 44: goto st58;
		case 47: goto tr284;
		case 93: goto tr92;
	}
	goto st57;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	switch( (*p) ) {
		case 10: goto st407;
		case 42: goto st413;
	}
	goto st412;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	switch( (*p) ) {
		case 10: goto st407;
		case 42: goto st413;
		case 47: goto st414;
	}
	goto st412;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	switch( (*p) ) {
		case 9: goto st414;
		case 10: goto st195;
		case 13: goto st414;
		case 32: goto st414;
		case 47: goto tr580;
		case 93: goto tr584;
	}
	goto tr93;
tr574:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st674;
st674:
	if ( ++p == pe )
		goto _test_eof674;
case 674:
#line 8060 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st186;
	goto st185;
tr577:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 415;goto st612;} }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 8071 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st407;
		case 32: goto st407;
		case 42: goto st416;
		case 44: goto st408;
		case 47: goto tr586;
		case 93: goto tr574;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st407;
	goto st185;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 42: goto st418;
		case 47: goto st524;
	}
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	if ( (*p) == 42 )
		goto st418;
	goto st417;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	switch( (*p) ) {
		case 42: goto st418;
		case 47: goto st419;
	}
	goto st417;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 13: goto st419;
		case 32: goto st419;
		case 47: goto tr591;
		case 93: goto tr592;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st419;
	goto tr58;
tr591:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 420;goto st612;} }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 8128 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st40;
		case 32: goto st40;
		case 42: goto st417;
		case 44: goto st41;
		case 47: goto tr593;
		case 93: goto tr65;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st40;
	goto st0;
tr593:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 8146 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st419;
		case 42: goto st423;
		case 47: goto st218;
	}
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	if ( (*p) == 10 )
		goto st419;
	goto st422;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	switch( (*p) ) {
		case 10: goto st424;
		case 42: goto st481;
	}
	goto st423;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	switch( (*p) ) {
		case 13: goto st424;
		case 32: goto st424;
		case 42: goto tr77;
		case 47: goto tr598;
		case 93: goto tr599;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st424;
	goto tr76;
tr598:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 425;goto st612;} }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 8190 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st49;
		case 32: goto st49;
		case 42: goto st426;
		case 44: goto st48;
		case 47: goto tr601;
		case 93: goto tr84;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st49;
	goto st50;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st427;
	}
	goto st213;
tr606:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 427;goto st612;} }
	goto st427;
tr609:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 8224 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st427;
		case 32: goto st427;
		case 42: goto st418;
		case 44: goto st428;
		case 47: goto tr604;
		case 93: goto tr605;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st427;
	goto st417;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	switch( (*p) ) {
		case 13: goto st428;
		case 32: goto st428;
		case 42: goto tr607;
		case 47: goto tr608;
		case 93: goto tr609;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st428;
	goto tr606;
tr607:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 429;goto st612;} }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 8256 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st427;
		case 32: goto st427;
		case 42: goto st418;
		case 44: goto st428;
		case 47: goto tr610;
		case 93: goto tr605;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st427;
	goto st417;
tr610:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 8274 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st419;
		case 32: goto st419;
		case 42: goto tr76;
		case 47: goto tr611;
		case 93: goto tr592;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st419;
	goto tr58;
tr611:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 431;goto st612;} }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 8292 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st40;
		case 13: goto st56;
		case 32: goto st56;
		case 42: goto st432;
		case 44: goto st58;
		case 47: goto tr314;
		case 93: goto tr92;
	}
	goto st57;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 10: goto st427;
		case 42: goto st433;
	}
	goto st432;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 10: goto st427;
		case 42: goto st433;
		case 47: goto st434;
	}
	goto st432;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 9: goto st434;
		case 10: goto st215;
		case 13: goto st434;
		case 32: goto st434;
		case 47: goto tr611;
		case 93: goto tr615;
	}
	goto tr93;
tr605:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st675;
st675:
	if ( ++p == pe )
		goto _test_eof675;
case 675:
#line 8346 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 42 )
		goto st418;
	goto st417;
tr608:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 435;goto st612;} }
	goto st435;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
#line 8357 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st427;
		case 32: goto st427;
		case 42: goto st436;
		case 44: goto st428;
		case 47: goto tr617;
		case 93: goto tr605;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st427;
	goto st417;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	switch( (*p) ) {
		case 42: goto st418;
		case 47: goto st437;
	}
	goto st417;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	switch( (*p) ) {
		case 13: goto st437;
		case 32: goto st437;
		case 42: goto tr131;
		case 47: goto tr619;
		case 93: goto tr620;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st437;
	goto tr130;
tr619:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 438;goto st612;} }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 8399 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st439;
		case 44: goto st85;
		case 47: goto tr622;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	switch( (*p) ) {
		case 42: goto st418;
		case 47: goto st428;
	}
	goto st417;
tr622:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 8426 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st437;
		case 42: goto st446;
		case 47: goto st237;
	}
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 10: goto st437;
		case 42: goto st442;
	}
	goto st441;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 10: goto st437;
		case 42: goto st442;
		case 47: goto st443;
	}
	goto st441;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	switch( (*p) ) {
		case 9: goto st443;
		case 10: goto st419;
		case 13: goto st443;
		case 32: goto st443;
		case 47: goto tr628;
		case 93: goto tr629;
	}
	goto tr627;
tr627:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 444;goto st612;} }
	goto st444;
tr629:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 8478 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st444;
		case 10: goto st215;
		case 13: goto st444;
		case 32: goto st444;
		case 44: goto st443;
		case 47: goto tr593;
		case 93: goto tr631;
	}
	goto st422;
tr631:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st676;
st676:
	if ( ++p == pe )
		goto _test_eof676;
case 676:
#line 8499 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st419;
	goto st422;
tr628:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 445;goto st612;} }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 8510 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st444;
		case 10: goto st215;
		case 13: goto st444;
		case 32: goto st444;
		case 42: goto st441;
		case 44: goto st443;
		case 47: goto tr593;
		case 93: goto tr631;
	}
	goto st422;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st482;
	}
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
	}
	goto st447;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	switch( (*p) ) {
		case 13: goto st448;
		case 32: goto st448;
		case 42: goto tr117;
		case 47: goto tr636;
		case 93: goto tr637;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st448;
	goto tr116;
tr636:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 449;goto st612;} }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 8562 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st450;
		case 44: goto st73;
		case 47: goto tr639;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st451;
	}
	goto st213;
tr641:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 451;goto st612;} }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 8589 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st451;
		case 32: goto st451;
		case 42: goto tr607;
		case 44: goto tr641;
		case 47: goto tr642;
		case 93: goto tr643;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st451;
	goto tr606;
tr642:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 452;goto st612;} }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 8608 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st427;
		case 32: goto st427;
		case 42: goto st453;
		case 44: goto st428;
		case 47: goto tr645;
		case 93: goto tr605;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st427;
	goto st417;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st448;
	}
	goto st213;
tr645:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 8635 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st459;
	}
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
	}
	goto st455;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
		case 47: goto st457;
	}
	goto st455;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
	switch( (*p) ) {
		case 9: goto st457;
		case 10: goto st215;
		case 13: goto st457;
		case 32: goto st457;
		case 47: goto tr650;
		case 93: goto tr651;
	}
	goto tr185;
tr650:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 458;goto st612;} }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 8680 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st455;
		case 44: goto st119;
		case 47: goto tr314;
		case 93: goto tr184;
	}
	goto st64;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st460;
	}
	goto st251;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	switch( (*p) ) {
		case 9: goto st460;
		case 10: goto st220;
		case 13: goto st460;
		case 32: goto st460;
		case 42: goto tr209;
		case 47: goto tr653;
		case 93: goto tr654;
	}
	goto tr208;
tr653:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 461;goto st612;} }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 8723 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st462;
		case 44: goto st142;
		case 47: goto tr322;
		case 93: goto tr214;
	}
	goto st65;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
	switch( (*p) ) {
		case 10: goto st247;
		case 42: goto st252;
		case 47: goto st463;
	}
	goto st251;
tr659:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 463;goto st612;} }
	goto st463;
tr662:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 8758 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st463;
		case 10: goto st451;
		case 13: goto st463;
		case 32: goto st463;
		case 42: goto st456;
		case 44: goto st464;
		case 47: goto tr645;
		case 93: goto tr658;
	}
	goto st455;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	switch( (*p) ) {
		case 9: goto st464;
		case 10: goto st451;
		case 13: goto st464;
		case 32: goto st464;
		case 42: goto tr660;
		case 47: goto tr661;
		case 93: goto tr662;
	}
	goto tr659;
tr660:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 465;goto st612;} }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 8790 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st463;
		case 10: goto st451;
		case 13: goto st463;
		case 32: goto st463;
		case 42: goto st456;
		case 44: goto st464;
		case 47: goto tr663;
		case 93: goto tr658;
	}
	goto st455;
tr663:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 8808 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st457;
		case 10: goto st215;
		case 13: goto st457;
		case 32: goto st457;
		case 42: goto tr208;
		case 47: goto tr650;
		case 93: goto tr651;
	}
	goto tr185;
tr658:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st677;
st677:
	if ( ++p == pe )
		goto _test_eof677;
case 677:
#line 8829 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
	}
	goto st455;
tr661:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 467;goto st612;} }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 8842 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st463;
		case 10: goto st451;
		case 13: goto st463;
		case 32: goto st463;
		case 42: goto st468;
		case 44: goto st464;
		case 47: goto tr645;
		case 93: goto tr658;
	}
	goto st455;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
		case 47: goto st469;
	}
	goto st455;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	switch( (*p) ) {
		case 9: goto st469;
		case 10: goto st233;
		case 13: goto st469;
		case 32: goto st469;
		case 42: goto tr223;
		case 47: goto tr666;
		case 93: goto tr667;
	}
	goto tr222;
tr666:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 470;goto st612;} }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 8885 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st471;
		case 44: goto st148;
		case 47: goto tr343;
		case 93: goto tr221;
	}
	goto st120;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
		case 47: goto st464;
	}
	goto st455;
tr643:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st678;
st678:
	if ( ++p == pe )
		goto _test_eof678;
case 678:
#line 8918 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st427;
		case 32: goto st427;
		case 42: goto st418;
		case 44: goto st428;
		case 47: goto tr604;
		case 93: goto tr605;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st427;
	goto st417;
tr604:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 8936 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st473;
		case 47: goto st432;
	}
	goto st417;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st424;
	}
	goto st213;
tr639:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 8957 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st475;
		case 47: goto st243;
	}
	goto st447;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st479;
	}
	goto st447;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st477;
	}
	goto st447;
tr673:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 477;goto st612;} }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 8990 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st477;
		case 10: goto st215;
		case 13: goto st477;
		case 32: goto st477;
		case 44: goto tr673;
		case 47: goto tr674;
		case 93: goto tr675;
	}
	goto tr627;
tr674:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 478;goto st612;} }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 9008 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st444;
		case 10: goto st215;
		case 13: goto st444;
		case 32: goto st444;
		case 42: goto st447;
		case 44: goto st443;
		case 47: goto tr314;
		case 93: goto tr631;
	}
	goto st422;
tr675:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st679;
st679:
	if ( ++p == pe )
		goto _test_eof679;
case 679:
#line 9031 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st444;
		case 10: goto st215;
		case 13: goto st444;
		case 32: goto st444;
		case 44: goto st443;
		case 47: goto tr593;
		case 93: goto tr631;
	}
	goto st422;
tr678:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 479;goto st612;} }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 9048 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st479;
		case 10: goto st220;
		case 13: goto st479;
		case 32: goto st479;
		case 42: goto tr677;
		case 44: goto tr678;
		case 47: goto tr679;
		case 93: goto tr680;
	}
	goto tr676;
tr676:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 480;goto st612;} }
	goto st480;
tr684:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st480;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
#line 9073 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st480;
		case 10: goto st220;
		case 13: goto st480;
		case 32: goto st480;
		case 42: goto st481;
		case 44: goto st482;
		case 47: goto tr601;
		case 93: goto tr682;
	}
	goto st423;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 10: goto st424;
		case 42: goto st481;
		case 47: goto st444;
	}
	goto st423;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	switch( (*p) ) {
		case 9: goto st482;
		case 10: goto st424;
		case 13: goto st482;
		case 32: goto st482;
		case 42: goto tr677;
		case 47: goto tr683;
		case 93: goto tr684;
	}
	goto tr676;
tr677:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 483;goto st612;} }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 9115 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st480;
		case 10: goto st220;
		case 13: goto st480;
		case 32: goto st480;
		case 42: goto st481;
		case 44: goto st482;
		case 47: goto tr685;
		case 93: goto tr682;
	}
	goto st423;
tr685:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 9133 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st444;
		case 10: goto st215;
		case 13: goto st444;
		case 32: goto st444;
		case 42: goto st423;
		case 44: goto st443;
		case 47: goto tr314;
		case 93: goto tr631;
	}
	goto st422;
tr682:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st680;
st680:
	if ( ++p == pe )
		goto _test_eof680;
case 680:
#line 9155 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st424;
		case 42: goto st481;
	}
	goto st423;
tr683:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 485;goto st612;} }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 9168 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st480;
		case 10: goto st220;
		case 13: goto st480;
		case 32: goto st480;
		case 42: goto st486;
		case 44: goto st482;
		case 47: goto tr601;
		case 93: goto tr682;
	}
	goto st423;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st487;
	}
	goto st447;
tr690:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 487;goto st612;} }
	goto st487;
tr693:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 9203 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st487;
		case 10: goto st233;
		case 13: goto st487;
		case 32: goto st487;
		case 42: goto st442;
		case 44: goto st488;
		case 47: goto tr622;
		case 93: goto tr689;
	}
	goto st441;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	switch( (*p) ) {
		case 9: goto st488;
		case 10: goto st437;
		case 13: goto st488;
		case 32: goto st488;
		case 42: goto tr691;
		case 47: goto tr692;
		case 93: goto tr693;
	}
	goto tr690;
tr691:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 489;goto st612;} }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 9235 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st487;
		case 10: goto st233;
		case 13: goto st487;
		case 32: goto st487;
		case 42: goto st442;
		case 44: goto st488;
		case 47: goto tr694;
		case 93: goto tr689;
	}
	goto st441;
tr694:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 9253 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st443;
		case 10: goto st419;
		case 13: goto st443;
		case 32: goto st443;
		case 42: goto tr676;
		case 47: goto tr349;
		case 93: goto tr629;
	}
	goto tr627;
tr689:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st681;
st681:
	if ( ++p == pe )
		goto _test_eof681;
case 681:
#line 9274 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st437;
		case 42: goto st442;
	}
	goto st441;
tr692:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 491;goto st612;} }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 9287 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st487;
		case 10: goto st233;
		case 13: goto st487;
		case 32: goto st487;
		case 42: goto st492;
		case 44: goto st488;
		case 47: goto tr622;
		case 93: goto tr689;
	}
	goto st441;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
	switch( (*p) ) {
		case 10: goto st437;
		case 42: goto st442;
		case 47: goto st488;
	}
	goto st441;
tr601:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 9315 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st424;
		case 42: goto st494;
		case 47: goto st219;
	}
	goto st423;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	switch( (*p) ) {
		case 10: goto st424;
		case 42: goto st481;
		case 47: goto st480;
	}
	goto st423;
tr679:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 495;goto st612;} }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 9339 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st480;
		case 10: goto st220;
		case 13: goto st480;
		case 32: goto st480;
		case 42: goto st496;
		case 44: goto st482;
		case 47: goto tr322;
		case 93: goto tr682;
	}
	goto st423;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st497;
	}
	goto st447;
tr701:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 497;goto st612;} }
	goto st497;
tr704:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 9374 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st497;
		case 10: goto st244;
		case 13: goto st497;
		case 32: goto st497;
		case 42: goto st476;
		case 44: goto st498;
		case 47: goto tr639;
		case 93: goto tr700;
	}
	goto st447;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	switch( (*p) ) {
		case 9: goto st498;
		case 10: goto st448;
		case 13: goto st498;
		case 32: goto st498;
		case 42: goto tr702;
		case 47: goto tr703;
		case 93: goto tr704;
	}
	goto tr701;
tr702:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 499;goto st612;} }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 9406 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st497;
		case 10: goto st244;
		case 13: goto st497;
		case 32: goto st497;
		case 42: goto st476;
		case 44: goto st498;
		case 47: goto tr705;
		case 93: goto tr700;
	}
	goto st447;
tr705:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 9424 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st477;
		case 10: goto st215;
		case 13: goto st477;
		case 32: goto st477;
		case 42: goto tr676;
		case 44: goto tr673;
		case 47: goto tr402;
		case 93: goto tr675;
	}
	goto tr627;
tr700:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st682;
st682:
	if ( ++p == pe )
		goto _test_eof682;
case 682:
#line 9446 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
	}
	goto st447;
tr703:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 501;goto st612;} }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 9459 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st497;
		case 10: goto st244;
		case 13: goto st497;
		case 32: goto st497;
		case 42: goto st502;
		case 44: goto st498;
		case 47: goto tr639;
		case 93: goto tr700;
	}
	goto st447;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st503;
	}
	goto st447;
tr708:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 503;goto st612;} }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 9487 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st503;
		case 10: goto st233;
		case 13: goto st503;
		case 32: goto st503;
		case 42: goto tr691;
		case 44: goto tr708;
		case 47: goto tr709;
		case 93: goto tr710;
	}
	goto tr690;
tr709:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 504;goto st612;} }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 9506 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st487;
		case 10: goto st233;
		case 13: goto st487;
		case 32: goto st487;
		case 42: goto st505;
		case 44: goto st488;
		case 47: goto tr343;
		case 93: goto tr689;
	}
	goto st441;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
	switch( (*p) ) {
		case 10: goto st448;
		case 42: goto st476;
		case 47: goto st498;
	}
	goto st447;
tr710:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st683;
st683:
	if ( ++p == pe )
		goto _test_eof683;
case 683:
#line 9539 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st487;
		case 10: goto st233;
		case 13: goto st487;
		case 32: goto st487;
		case 42: goto st442;
		case 44: goto st488;
		case 47: goto tr622;
		case 93: goto tr689;
	}
	goto st441;
tr680:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st684;
st684:
	if ( ++p == pe )
		goto _test_eof684;
case 684:
#line 9562 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st480;
		case 10: goto st220;
		case 13: goto st480;
		case 32: goto st480;
		case 42: goto st481;
		case 44: goto st482;
		case 47: goto tr601;
		case 93: goto tr682;
	}
	goto st423;
tr617:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 9580 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st511;
		case 47: goto st455;
	}
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
	}
	goto st507;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
		case 47: goto st509;
	}
	goto st507;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
	switch( (*p) ) {
		case 9: goto st509;
		case 10: goto st419;
		case 13: goto st509;
		case 32: goto st509;
		case 47: goto tr716;
		case 93: goto tr717;
	}
	goto tr151;
tr716:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 510;goto st612;} }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 9626 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st507;
		case 44: goto st96;
		case 47: goto tr593;
		case 93: goto tr155;
	}
	goto st46;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st512;
	}
	goto st303;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	switch( (*p) ) {
		case 9: goto st512;
		case 10: goto st424;
		case 13: goto st512;
		case 32: goto st512;
		case 42: goto tr164;
		case 47: goto tr719;
		case 93: goto tr720;
	}
	goto tr163;
tr719:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 513;goto st612;} }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 9669 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st514;
		case 44: goto st104;
		case 47: goto tr601;
		case 93: goto tr169;
	}
	goto st47;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	switch( (*p) ) {
		case 10: goto st224;
		case 42: goto st304;
		case 47: goto st515;
	}
	goto st303;
tr725:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 515;goto st612;} }
	goto st515;
tr728:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 9704 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st515;
		case 10: goto st451;
		case 13: goto st515;
		case 32: goto st515;
		case 42: goto st508;
		case 44: goto st516;
		case 47: goto tr617;
		case 93: goto tr724;
	}
	goto st507;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	switch( (*p) ) {
		case 9: goto st516;
		case 10: goto st428;
		case 13: goto st516;
		case 32: goto st516;
		case 42: goto tr726;
		case 47: goto tr727;
		case 93: goto tr728;
	}
	goto tr725;
tr726:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 517;goto st612;} }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 9736 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st515;
		case 10: goto st451;
		case 13: goto st515;
		case 32: goto st515;
		case 42: goto st508;
		case 44: goto st516;
		case 47: goto tr729;
		case 93: goto tr724;
	}
	goto st507;
tr729:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 9754 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st509;
		case 10: goto st419;
		case 13: goto st509;
		case 32: goto st509;
		case 42: goto tr163;
		case 47: goto tr650;
		case 93: goto tr717;
	}
	goto tr151;
tr724:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st685;
st685:
	if ( ++p == pe )
		goto _test_eof685;
case 685:
#line 9775 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
	}
	goto st507;
tr727:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 519;goto st612;} }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 9788 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st515;
		case 10: goto st451;
		case 13: goto st515;
		case 32: goto st515;
		case 42: goto st520;
		case 44: goto st516;
		case 47: goto tr617;
		case 93: goto tr724;
	}
	goto st507;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
		case 47: goto st521;
	}
	goto st507;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	switch( (*p) ) {
		case 9: goto st521;
		case 10: goto st437;
		case 13: goto st521;
		case 32: goto st521;
		case 42: goto tr177;
		case 47: goto tr732;
		case 93: goto tr733;
	}
	goto tr176;
tr732:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 522;goto st612;} }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 9831 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st523;
		case 44: goto st114;
		case 47: goto tr622;
		case 93: goto tr175;
	}
	goto st94;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
		case 47: goto st516;
	}
	goto st507;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
	switch( (*p) ) {
		case 13: goto st524;
		case 32: goto st524;
		case 42: goto tr131;
		case 47: goto tr735;
		case 93: goto tr736;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st524;
	goto tr130;
tr735:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 525;goto st612;} }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 9874 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st84;
		case 32: goto st84;
		case 42: goto st526;
		case 44: goto st85;
		case 47: goto tr738;
		case 93: goto tr138;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st84;
	goto st43;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	switch( (*p) ) {
		case 42: goto st418;
		case 47: goto st408;
	}
	goto st417;
tr738:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 9901 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st524;
		case 42: goto st533;
		case 47: goto st324;
	}
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
	switch( (*p) ) {
		case 10: goto st524;
		case 42: goto st529;
	}
	goto st528;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	switch( (*p) ) {
		case 10: goto st524;
		case 42: goto st529;
		case 47: goto st530;
	}
	goto st528;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	switch( (*p) ) {
		case 9: goto st530;
		case 10: goto st419;
		case 13: goto st530;
		case 32: goto st530;
		case 47: goto tr744;
		case 93: goto tr745;
	}
	goto tr743;
tr743:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 531;goto st612;} }
	goto st531;
tr745:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st531;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
#line 9953 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st531;
		case 10: goto st195;
		case 13: goto st531;
		case 32: goto st531;
		case 44: goto st530;
		case 47: goto tr267;
		case 93: goto tr747;
	}
	goto st188;
tr747:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st686;
st686:
	if ( ++p == pe )
		goto _test_eof686;
case 686:
#line 9974 "/home/xero/code/github.com/kJSON/src/kjson.c"
	if ( (*p) == 10 )
		goto st39;
	goto st188;
tr744:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 532;goto st612;} }
	goto st532;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
#line 9985 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st531;
		case 10: goto st195;
		case 13: goto st531;
		case 32: goto st531;
		case 42: goto st528;
		case 44: goto st530;
		case 47: goto tr593;
		case 93: goto tr747;
	}
	goto st188;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st569;
	}
	goto st534;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
	}
	goto st534;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	switch( (*p) ) {
		case 13: goto st535;
		case 32: goto st535;
		case 42: goto tr117;
		case 47: goto tr752;
		case 93: goto tr753;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st535;
	goto tr116;
tr752:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 536;goto st612;} }
	goto st536;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
#line 10037 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st72;
		case 32: goto st72;
		case 42: goto st537;
		case 44: goto st73;
		case 47: goto tr755;
		case 93: goto tr115;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto st61;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st538;
	}
	goto st213;
tr757:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 538;goto st612;} }
	goto st538;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
#line 10064 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st538;
		case 32: goto st538;
		case 42: goto tr576;
		case 44: goto tr757;
		case 47: goto tr758;
		case 93: goto tr759;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st538;
	goto tr575;
tr758:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 539;goto st612;} }
	goto st539;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
#line 10083 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st407;
		case 32: goto st407;
		case 42: goto st540;
		case 44: goto st408;
		case 47: goto tr761;
		case 93: goto tr574;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st407;
	goto st185;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
	switch( (*p) ) {
		case 42: goto st214;
		case 47: goto st535;
	}
	goto st213;
tr761:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st541;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
#line 10110 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st538;
		case 42: goto st546;
	}
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
	switch( (*p) ) {
		case 10: goto st538;
		case 42: goto st543;
	}
	goto st542;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
	switch( (*p) ) {
		case 10: goto st538;
		case 42: goto st543;
		case 47: goto st544;
	}
	goto st542;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
	switch( (*p) ) {
		case 9: goto st544;
		case 10: goto st215;
		case 13: goto st544;
		case 32: goto st544;
		case 47: goto tr766;
		case 93: goto tr767;
	}
	goto tr185;
tr766:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 545;goto st612;} }
	goto st545;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
#line 10155 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st118;
		case 10: goto st59;
		case 13: goto st118;
		case 32: goto st118;
		case 42: goto st542;
		case 44: goto st119;
		case 47: goto tr314;
		case 93: goto tr184;
	}
	goto st64;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
		case 47: goto st547;
	}
	goto st338;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	switch( (*p) ) {
		case 9: goto st547;
		case 10: goto st220;
		case 13: goto st547;
		case 32: goto st547;
		case 42: goto tr209;
		case 47: goto tr769;
		case 93: goto tr770;
	}
	goto tr208;
tr769:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 548;goto st612;} }
	goto st548;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
#line 10198 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st140;
		case 10: goto st66;
		case 13: goto st140;
		case 32: goto st140;
		case 42: goto st549;
		case 44: goto st142;
		case 47: goto tr322;
		case 93: goto tr214;
	}
	goto st65;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	switch( (*p) ) {
		case 10: goto st334;
		case 42: goto st339;
		case 47: goto st550;
	}
	goto st338;
tr775:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 550;goto st612;} }
	goto st550;
tr778:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st550;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
#line 10233 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st550;
		case 10: goto st538;
		case 13: goto st550;
		case 32: goto st550;
		case 42: goto st543;
		case 44: goto st551;
		case 47: goto tr761;
		case 93: goto tr774;
	}
	goto st542;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 9: goto st551;
		case 10: goto st538;
		case 13: goto st551;
		case 32: goto st551;
		case 42: goto tr776;
		case 47: goto tr777;
		case 93: goto tr778;
	}
	goto tr775;
tr776:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 552;goto st612;} }
	goto st552;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
#line 10265 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st550;
		case 10: goto st538;
		case 13: goto st550;
		case 32: goto st550;
		case 42: goto st543;
		case 44: goto st551;
		case 47: goto tr779;
		case 93: goto tr774;
	}
	goto st542;
tr779:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st553;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
#line 10283 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st544;
		case 10: goto st215;
		case 13: goto st544;
		case 32: goto st544;
		case 42: goto tr208;
		case 47: goto tr766;
		case 93: goto tr767;
	}
	goto tr185;
tr774:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st687;
st687:
	if ( ++p == pe )
		goto _test_eof687;
case 687:
#line 10304 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st538;
		case 42: goto st543;
	}
	goto st542;
tr777:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 554;goto st612;} }
	goto st554;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
#line 10317 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st550;
		case 10: goto st538;
		case 13: goto st550;
		case 32: goto st550;
		case 42: goto st555;
		case 44: goto st551;
		case 47: goto tr761;
		case 93: goto tr774;
	}
	goto st542;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
		case 47: goto st556;
	}
	goto st455;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
	switch( (*p) ) {
		case 9: goto st556;
		case 10: goto st233;
		case 13: goto st556;
		case 32: goto st556;
		case 42: goto tr223;
		case 47: goto tr782;
		case 93: goto tr783;
	}
	goto tr222;
tr782:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 557;goto st612;} }
	goto st557;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
#line 10360 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st147;
		case 10: goto st83;
		case 13: goto st147;
		case 32: goto st147;
		case 42: goto st558;
		case 44: goto st148;
		case 47: goto tr343;
		case 93: goto tr221;
	}
	goto st120;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
	switch( (*p) ) {
		case 10: goto st451;
		case 42: goto st456;
		case 47: goto st551;
	}
	goto st455;
tr759:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st688;
st688:
	if ( ++p == pe )
		goto _test_eof688;
case 688:
#line 10393 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto st407;
		case 32: goto st407;
		case 42: goto st186;
		case 44: goto st408;
		case 47: goto tr573;
		case 93: goto tr574;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st407;
	goto st185;
tr573:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st559;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
#line 10411 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st560;
		case 47: goto st412;
	}
	goto st185;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
	switch( (*p) ) {
		case 42: goto st194;
		case 47: goto st190;
	}
	goto st193;
tr755:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 10432 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st562;
		case 47: goto st330;
	}
	goto st534;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st566;
	}
	goto st534;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st564;
	}
	goto st534;
tr789:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 564;goto st612;} }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 10465 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st564;
		case 10: goto st215;
		case 13: goto st564;
		case 32: goto st564;
		case 44: goto tr789;
		case 47: goto tr790;
		case 93: goto tr791;
	}
	goto tr743;
tr790:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 565;goto st612;} }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 10483 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st531;
		case 10: goto st195;
		case 13: goto st531;
		case 32: goto st531;
		case 42: goto st534;
		case 44: goto st530;
		case 47: goto tr314;
		case 93: goto tr747;
	}
	goto st188;
tr791:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st689;
st689:
	if ( ++p == pe )
		goto _test_eof689;
case 689:
#line 10506 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st531;
		case 10: goto st195;
		case 13: goto st531;
		case 32: goto st531;
		case 44: goto st530;
		case 47: goto tr267;
		case 93: goto tr747;
	}
	goto st188;
tr794:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 566;goto st612;} }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 10523 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st566;
		case 10: goto st220;
		case 13: goto st566;
		case 32: goto st566;
		case 42: goto tr793;
		case 44: goto tr794;
		case 47: goto tr795;
		case 93: goto tr796;
	}
	goto tr792;
tr792:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 567;goto st612;} }
	goto st567;
tr800:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st567;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
#line 10548 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st567;
		case 10: goto st200;
		case 13: goto st567;
		case 32: goto st567;
		case 42: goto st568;
		case 44: goto st569;
		case 47: goto tr277;
		case 93: goto tr798;
	}
	goto st189;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
	switch( (*p) ) {
		case 10: goto st190;
		case 42: goto st568;
		case 47: goto st531;
	}
	goto st189;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
	switch( (*p) ) {
		case 9: goto st569;
		case 10: goto st424;
		case 13: goto st569;
		case 32: goto st569;
		case 42: goto tr793;
		case 47: goto tr799;
		case 93: goto tr800;
	}
	goto tr792;
tr793:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 570;goto st612;} }
	goto st570;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
#line 10590 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st567;
		case 10: goto st200;
		case 13: goto st567;
		case 32: goto st567;
		case 42: goto st568;
		case 44: goto st569;
		case 47: goto tr801;
		case 93: goto tr798;
	}
	goto st189;
tr801:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 10608 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st531;
		case 10: goto st195;
		case 13: goto st531;
		case 32: goto st531;
		case 42: goto st189;
		case 44: goto st530;
		case 47: goto tr284;
		case 93: goto tr747;
	}
	goto st188;
tr798:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st690;
st690:
	if ( ++p == pe )
		goto _test_eof690;
case 690:
#line 10630 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st190;
		case 42: goto st568;
	}
	goto st189;
tr799:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 572;goto st612;} }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 10643 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st567;
		case 10: goto st200;
		case 13: goto st567;
		case 32: goto st567;
		case 42: goto st573;
		case 44: goto st569;
		case 47: goto tr601;
		case 93: goto tr798;
	}
	goto st189;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st574;
	}
	goto st534;
tr806:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 574;goto st612;} }
	goto st574;
tr809:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 10678 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st574;
		case 10: goto st320;
		case 13: goto st574;
		case 32: goto st574;
		case 42: goto st529;
		case 44: goto st575;
		case 47: goto tr738;
		case 93: goto tr805;
	}
	goto st528;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
	switch( (*p) ) {
		case 9: goto st575;
		case 10: goto st437;
		case 13: goto st575;
		case 32: goto st575;
		case 42: goto tr807;
		case 47: goto tr808;
		case 93: goto tr809;
	}
	goto tr806;
tr807:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 576;goto st612;} }
	goto st576;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
#line 10710 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st574;
		case 10: goto st320;
		case 13: goto st574;
		case 32: goto st574;
		case 42: goto st529;
		case 44: goto st575;
		case 47: goto tr810;
		case 93: goto tr805;
	}
	goto st528;
tr810:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st577;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
#line 10728 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st530;
		case 10: goto st419;
		case 13: goto st530;
		case 32: goto st530;
		case 42: goto tr792;
		case 47: goto tr465;
		case 93: goto tr745;
	}
	goto tr743;
tr805:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st691;
st691:
	if ( ++p == pe )
		goto _test_eof691;
case 691:
#line 10749 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st524;
		case 42: goto st529;
	}
	goto st528;
tr808:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 578;goto st612;} }
	goto st578;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
#line 10762 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st574;
		case 10: goto st320;
		case 13: goto st574;
		case 32: goto st574;
		case 42: goto st579;
		case 44: goto st575;
		case 47: goto tr622;
		case 93: goto tr805;
	}
	goto st528;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
	switch( (*p) ) {
		case 10: goto st524;
		case 42: goto st529;
		case 47: goto st575;
	}
	goto st528;
tr277:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st580;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
#line 10790 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st190;
		case 42: goto st581;
		case 47: goto st199;
	}
	goto st189;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
	switch( (*p) ) {
		case 10: goto st190;
		case 42: goto st568;
		case 47: goto st567;
	}
	goto st189;
tr795:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 582;goto st612;} }
	goto st582;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
#line 10814 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st567;
		case 10: goto st200;
		case 13: goto st567;
		case 32: goto st567;
		case 42: goto st583;
		case 44: goto st569;
		case 47: goto tr322;
		case 93: goto tr798;
	}
	goto st189;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st584;
	}
	goto st534;
tr817:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 584;goto st612;} }
	goto st584;
tr820:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st584;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
#line 10849 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st584;
		case 10: goto st331;
		case 13: goto st584;
		case 32: goto st584;
		case 42: goto st563;
		case 44: goto st585;
		case 47: goto tr755;
		case 93: goto tr816;
	}
	goto st534;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	switch( (*p) ) {
		case 9: goto st585;
		case 10: goto st448;
		case 13: goto st585;
		case 32: goto st585;
		case 42: goto tr818;
		case 47: goto tr819;
		case 93: goto tr820;
	}
	goto tr817;
tr818:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 586;goto st612;} }
	goto st586;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
#line 10881 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st584;
		case 10: goto st331;
		case 13: goto st584;
		case 32: goto st584;
		case 42: goto st563;
		case 44: goto st585;
		case 47: goto tr821;
		case 93: goto tr816;
	}
	goto st534;
tr821:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st587;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
#line 10899 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st564;
		case 10: goto st215;
		case 13: goto st564;
		case 32: goto st564;
		case 42: goto tr792;
		case 44: goto tr789;
		case 47: goto tr511;
		case 93: goto tr791;
	}
	goto tr743;
tr816:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st692;
st692:
	if ( ++p == pe )
		goto _test_eof692;
case 692:
#line 10921 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
	}
	goto st534;
tr819:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 588;goto st612;} }
	goto st588;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
#line 10934 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st584;
		case 10: goto st331;
		case 13: goto st584;
		case 32: goto st584;
		case 42: goto st589;
		case 44: goto st585;
		case 47: goto tr639;
		case 93: goto tr816;
	}
	goto st534;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st590;
	}
	goto st534;
tr824:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 590;goto st612;} }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 10962 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st590;
		case 10: goto st233;
		case 13: goto st590;
		case 32: goto st590;
		case 42: goto tr807;
		case 44: goto tr824;
		case 47: goto tr825;
		case 93: goto tr826;
	}
	goto tr806;
tr825:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 591;goto st612;} }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 10981 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st574;
		case 10: goto st320;
		case 13: goto st574;
		case 32: goto st574;
		case 42: goto st592;
		case 44: goto st575;
		case 47: goto tr343;
		case 93: goto tr805;
	}
	goto st528;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	switch( (*p) ) {
		case 10: goto st535;
		case 42: goto st563;
		case 47: goto st585;
	}
	goto st534;
tr826:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st693;
st693:
	if ( ++p == pe )
		goto _test_eof693;
case 693:
#line 11014 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st574;
		case 10: goto st320;
		case 13: goto st574;
		case 32: goto st574;
		case 42: goto st529;
		case 44: goto st575;
		case 47: goto tr738;
		case 93: goto tr805;
	}
	goto st528;
tr796:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st694;
st694:
	if ( ++p == pe )
		goto _test_eof694;
case 694:
#line 11037 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st567;
		case 10: goto st200;
		case 13: goto st567;
		case 32: goto st567;
		case 42: goto st568;
		case 44: goto st569;
		case 47: goto tr277;
		case 93: goto tr798;
	}
	goto st189;
tr586:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 11055 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st408;
		case 42: goto st598;
		case 47: goto st542;
	}
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
	switch( (*p) ) {
		case 10: goto st408;
		case 42: goto st595;
	}
	goto st594;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
	switch( (*p) ) {
		case 10: goto st408;
		case 42: goto st595;
		case 47: goto st596;
	}
	goto st594;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	switch( (*p) ) {
		case 9: goto st596;
		case 10: goto st419;
		case 13: goto st596;
		case 32: goto st596;
		case 47: goto tr832;
		case 93: goto tr833;
	}
	goto tr151;
tr832:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 597;goto st612;} }
	goto st597;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
#line 11101 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st97;
		case 10: goto st59;
		case 13: goto st97;
		case 32: goto st97;
		case 42: goto st594;
		case 44: goto st96;
		case 47: goto tr593;
		case 93: goto tr155;
	}
	goto st46;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
		case 47: goto st599;
	}
	goto st390;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	switch( (*p) ) {
		case 9: goto st599;
		case 10: goto st424;
		case 13: goto st599;
		case 32: goto st599;
		case 42: goto tr164;
		case 47: goto tr835;
		case 93: goto tr836;
	}
	goto tr163;
tr835:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 600;goto st612;} }
	goto st600;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
#line 11144 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st105;
		case 10: goto st66;
		case 13: goto st105;
		case 32: goto st105;
		case 42: goto st601;
		case 44: goto st104;
		case 47: goto tr601;
		case 93: goto tr169;
	}
	goto st47;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	switch( (*p) ) {
		case 10: goto st204;
		case 42: goto st391;
		case 47: goto st602;
	}
	goto st390;
tr841:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 602;goto st612;} }
	goto st602;
tr844:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 112 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st602;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
#line 11179 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st602;
		case 10: goto st538;
		case 13: goto st602;
		case 32: goto st602;
		case 42: goto st595;
		case 44: goto st603;
		case 47: goto tr586;
		case 93: goto tr840;
	}
	goto st594;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	switch( (*p) ) {
		case 9: goto st603;
		case 10: goto st408;
		case 13: goto st603;
		case 32: goto st603;
		case 42: goto tr842;
		case 47: goto tr843;
		case 93: goto tr844;
	}
	goto tr841;
tr842:
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 604;goto st612;} }
	goto st604;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
#line 11211 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st602;
		case 10: goto st538;
		case 13: goto st602;
		case 32: goto st602;
		case 42: goto st595;
		case 44: goto st603;
		case 47: goto tr845;
		case 93: goto tr840;
	}
	goto st594;
tr845:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st605;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
#line 11229 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st596;
		case 10: goto st419;
		case 13: goto st596;
		case 32: goto st596;
		case 42: goto tr163;
		case 47: goto tr766;
		case 93: goto tr833;
	}
	goto tr151;
tr840:
#line 42 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_end) 
            handlers->on_array_end(p - data, user_data);
    }
#line 114 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st695;
st695:
	if ( ++p == pe )
		goto _test_eof695;
case 695:
#line 11250 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 10: goto st408;
		case 42: goto st595;
	}
	goto st594;
tr843:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 606;goto st612;} }
	goto st606;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
#line 11263 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st602;
		case 10: goto st538;
		case 13: goto st602;
		case 32: goto st602;
		case 42: goto st607;
		case 44: goto st603;
		case 47: goto tr586;
		case 93: goto tr840;
	}
	goto st594;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
		case 47: goto st608;
	}
	goto st507;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
	switch( (*p) ) {
		case 9: goto st608;
		case 10: goto st437;
		case 13: goto st608;
		case 32: goto st608;
		case 42: goto tr177;
		case 47: goto tr848;
		case 93: goto tr849;
	}
	goto tr176;
tr848:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
#line 74 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; {( parser->stack)[( parser->top)++] = 609;goto st612;} }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 11306 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 9: goto st113;
		case 10: goto st83;
		case 13: goto st113;
		case 32: goto st113;
		case 42: goto st610;
		case 44: goto st114;
		case 47: goto tr622;
		case 93: goto tr175;
	}
	goto st94;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
	switch( (*p) ) {
		case 10: goto st428;
		case 42: goto st508;
		case 47: goto st603;
	}
	goto st507;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	goto st0;
st612:
	if ( ++p == pe )
		goto _test_eof612;
case 612:
	switch( (*p) ) {
		case 13: goto st612;
		case 32: goto st612;
		case 34: goto tr853;
		case 39: goto tr854;
		case 44: goto st0;
		case 47: goto tr855;
		case 58: goto st0;
		case 91: goto tr856;
		case 93: goto st0;
		case 123: goto tr857;
		case 125: goto st0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st612;
	goto tr851;
tr851:
#line 76 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ parser->mark = p; }
	goto st613;
st613:
	if ( ++p == pe )
		goto _test_eof613;
case 613:
#line 11359 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr859;
		case 32: goto tr859;
		case 34: goto tr859;
		case 44: goto tr859;
		case 47: goto tr859;
		case 58: goto tr859;
		case 91: goto tr859;
		case 93: goto tr859;
		case 123: goto tr859;
		case 125: goto tr859;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr859;
	goto st613;
tr856:
#line 37 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_array_start) 
            handlers->on_array_start(p - data, user_data);
    }
#line 124 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {goto st39;} }
	goto st696;
tr857:
#line 27 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        if (handlers && handlers->on_object_start) 
            handlers->on_object_start(p - data, user_data);
    }
#line 123 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {goto st13;} }
	goto st696;
tr859:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 91 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; }
#line 75 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st696;
tr861:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 75 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st696;
st696:
	if ( ++p == pe )
		goto _test_eof696;
case 696:
#line 11409 "/home/xero/code/github.com/kJSON/src/kjson.c"
	goto st0;
tr853:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
	goto st614;
st614:
	if ( ++p == pe )
		goto _test_eof614;
case 614:
#line 11420 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 34: goto tr861;
		case 92: goto st615;
	}
	goto st614;
st615:
	if ( ++p == pe )
		goto _test_eof615;
case 615:
	goto st614;
tr854:
#line 23 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        parser->mark = p;
    }
#line 79 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_string: %c\n", *p); }
#line 76 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ parser->mark = p; }
	goto st616;
st616:
	if ( ++p == pe )
		goto _test_eof616;
case 616:
#line 11441 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr864;
		case 32: goto tr864;
		case 34: goto tr864;
		case 39: goto tr865;
		case 44: goto tr864;
		case 47: goto tr864;
		case 58: goto tr864;
		case 92: goto st619;
		case 123: goto tr864;
		case 125: goto tr864;
	}
	if ( (*p) > 10 ) {
		if ( 91 <= (*p) && (*p) <= 93 )
			goto tr864;
	} else if ( (*p) >= 9 )
		goto tr864;
	goto st616;
tr864:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 91 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ p--; }
#line 75 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st697;
st697:
	if ( ++p == pe )
		goto _test_eof697;
case 697:
#line 11472 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 39: goto tr861;
		case 92: goto st618;
	}
	goto st617;
st617:
	if ( ++p == pe )
		goto _test_eof617;
case 617:
	switch( (*p) ) {
		case 39: goto tr861;
		case 92: goto st618;
	}
	goto st617;
st618:
	if ( ++p == pe )
		goto _test_eof618;
case 618:
	goto st617;
tr865:
#line 52 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{
        printf("on_value called: %.*s\n", (int)(p - parser->mark), parser->mark);
        if (handlers && handlers->on_value)
            handlers->on_value(parser->mark, p - parser->mark, user_data);
    }
#line 75 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ {( parser->cs) = ( parser->stack)[--( parser->top)];goto _again;} }
	goto st698;
st698:
	if ( ++p == pe )
		goto _test_eof698;
case 698:
#line 11503 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 13: goto tr859;
		case 32: goto tr859;
		case 34: goto tr859;
		case 44: goto tr859;
		case 47: goto tr859;
		case 58: goto tr859;
		case 91: goto tr859;
		case 93: goto tr859;
		case 123: goto tr859;
		case 125: goto tr859;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr859;
	goto st613;
st619:
	if ( ++p == pe )
		goto _test_eof619;
case 619:
	switch( (*p) ) {
		case 13: goto tr864;
		case 32: goto tr864;
		case 34: goto tr864;
		case 44: goto tr864;
		case 47: goto tr864;
		case 58: goto tr864;
		case 91: goto tr864;
		case 93: goto tr864;
		case 123: goto tr864;
		case 125: goto tr864;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr864;
	goto st616;
tr855:
#line 64 "/home/xero/code/github.com/kJSON/src/kjson.rl"
	{ printf("debug_comment\n"); }
	goto st620;
st620:
	if ( ++p == pe )
		goto _test_eof620;
case 620:
#line 11544 "/home/xero/code/github.com/kJSON/src/kjson.c"
	switch( (*p) ) {
		case 42: goto st621;
		case 47: goto st623;
	}
	goto st0;
st621:
	if ( ++p == pe )
		goto _test_eof621;
case 621:
	if ( (*p) == 42 )
		goto st622;
	goto st621;
st622:
	if ( ++p == pe )
		goto _test_eof622;
case 622:
	switch( (*p) ) {
		case 42: goto st622;
		case 47: goto st612;
	}
	goto st621;
st623:
	if ( ++p == pe )
		goto _test_eof623;
case 623:
	if ( (*p) == 10 )
		goto st612;
	goto st623;
	}
	_test_eof1: ( parser->cs) = 1; goto _test_eof; 
	_test_eof2: ( parser->cs) = 2; goto _test_eof; 
	_test_eof624: ( parser->cs) = 624; goto _test_eof; 
	_test_eof3: ( parser->cs) = 3; goto _test_eof; 
	_test_eof4: ( parser->cs) = 4; goto _test_eof; 
	_test_eof5: ( parser->cs) = 5; goto _test_eof; 
	_test_eof625: ( parser->cs) = 625; goto _test_eof; 
	_test_eof6: ( parser->cs) = 6; goto _test_eof; 
	_test_eof7: ( parser->cs) = 7; goto _test_eof; 
	_test_eof626: ( parser->cs) = 626; goto _test_eof; 
	_test_eof8: ( parser->cs) = 8; goto _test_eof; 
	_test_eof9: ( parser->cs) = 9; goto _test_eof; 
	_test_eof10: ( parser->cs) = 10; goto _test_eof; 
	_test_eof11: ( parser->cs) = 11; goto _test_eof; 
	_test_eof12: ( parser->cs) = 12; goto _test_eof; 
	_test_eof13: ( parser->cs) = 13; goto _test_eof; 
	_test_eof14: ( parser->cs) = 14; goto _test_eof; 
	_test_eof15: ( parser->cs) = 15; goto _test_eof; 
	_test_eof16: ( parser->cs) = 16; goto _test_eof; 
	_test_eof17: ( parser->cs) = 17; goto _test_eof; 
	_test_eof18: ( parser->cs) = 18; goto _test_eof; 
	_test_eof19: ( parser->cs) = 19; goto _test_eof; 
	_test_eof20: ( parser->cs) = 20; goto _test_eof; 
	_test_eof21: ( parser->cs) = 21; goto _test_eof; 
	_test_eof22: ( parser->cs) = 22; goto _test_eof; 
	_test_eof23: ( parser->cs) = 23; goto _test_eof; 
	_test_eof24: ( parser->cs) = 24; goto _test_eof; 
	_test_eof25: ( parser->cs) = 25; goto _test_eof; 
	_test_eof26: ( parser->cs) = 26; goto _test_eof; 
	_test_eof27: ( parser->cs) = 27; goto _test_eof; 
	_test_eof28: ( parser->cs) = 28; goto _test_eof; 
	_test_eof29: ( parser->cs) = 29; goto _test_eof; 
	_test_eof30: ( parser->cs) = 30; goto _test_eof; 
	_test_eof31: ( parser->cs) = 31; goto _test_eof; 
	_test_eof32: ( parser->cs) = 32; goto _test_eof; 
	_test_eof33: ( parser->cs) = 33; goto _test_eof; 
	_test_eof627: ( parser->cs) = 627; goto _test_eof; 
	_test_eof34: ( parser->cs) = 34; goto _test_eof; 
	_test_eof35: ( parser->cs) = 35; goto _test_eof; 
	_test_eof36: ( parser->cs) = 36; goto _test_eof; 
	_test_eof37: ( parser->cs) = 37; goto _test_eof; 
	_test_eof38: ( parser->cs) = 38; goto _test_eof; 
	_test_eof39: ( parser->cs) = 39; goto _test_eof; 
	_test_eof40: ( parser->cs) = 40; goto _test_eof; 
	_test_eof41: ( parser->cs) = 41; goto _test_eof; 
	_test_eof42: ( parser->cs) = 42; goto _test_eof; 
	_test_eof43: ( parser->cs) = 43; goto _test_eof; 
	_test_eof44: ( parser->cs) = 44; goto _test_eof; 
	_test_eof45: ( parser->cs) = 45; goto _test_eof; 
	_test_eof46: ( parser->cs) = 46; goto _test_eof; 
	_test_eof47: ( parser->cs) = 47; goto _test_eof; 
	_test_eof48: ( parser->cs) = 48; goto _test_eof; 
	_test_eof49: ( parser->cs) = 49; goto _test_eof; 
	_test_eof50: ( parser->cs) = 50; goto _test_eof; 
	_test_eof51: ( parser->cs) = 51; goto _test_eof; 
	_test_eof52: ( parser->cs) = 52; goto _test_eof; 
	_test_eof53: ( parser->cs) = 53; goto _test_eof; 
	_test_eof54: ( parser->cs) = 54; goto _test_eof; 
	_test_eof55: ( parser->cs) = 55; goto _test_eof; 
	_test_eof56: ( parser->cs) = 56; goto _test_eof; 
	_test_eof57: ( parser->cs) = 57; goto _test_eof; 
	_test_eof58: ( parser->cs) = 58; goto _test_eof; 
	_test_eof59: ( parser->cs) = 59; goto _test_eof; 
	_test_eof60: ( parser->cs) = 60; goto _test_eof; 
	_test_eof61: ( parser->cs) = 61; goto _test_eof; 
	_test_eof62: ( parser->cs) = 62; goto _test_eof; 
	_test_eof63: ( parser->cs) = 63; goto _test_eof; 
	_test_eof64: ( parser->cs) = 64; goto _test_eof; 
	_test_eof65: ( parser->cs) = 65; goto _test_eof; 
	_test_eof66: ( parser->cs) = 66; goto _test_eof; 
	_test_eof67: ( parser->cs) = 67; goto _test_eof; 
	_test_eof68: ( parser->cs) = 68; goto _test_eof; 
	_test_eof69: ( parser->cs) = 69; goto _test_eof; 
	_test_eof628: ( parser->cs) = 628; goto _test_eof; 
	_test_eof629: ( parser->cs) = 629; goto _test_eof; 
	_test_eof70: ( parser->cs) = 70; goto _test_eof; 
	_test_eof71: ( parser->cs) = 71; goto _test_eof; 
	_test_eof72: ( parser->cs) = 72; goto _test_eof; 
	_test_eof73: ( parser->cs) = 73; goto _test_eof; 
	_test_eof74: ( parser->cs) = 74; goto _test_eof; 
	_test_eof75: ( parser->cs) = 75; goto _test_eof; 
	_test_eof76: ( parser->cs) = 76; goto _test_eof; 
	_test_eof77: ( parser->cs) = 77; goto _test_eof; 
	_test_eof78: ( parser->cs) = 78; goto _test_eof; 
	_test_eof79: ( parser->cs) = 79; goto _test_eof; 
	_test_eof630: ( parser->cs) = 630; goto _test_eof; 
	_test_eof631: ( parser->cs) = 631; goto _test_eof; 
	_test_eof632: ( parser->cs) = 632; goto _test_eof; 
	_test_eof80: ( parser->cs) = 80; goto _test_eof; 
	_test_eof633: ( parser->cs) = 633; goto _test_eof; 
	_test_eof81: ( parser->cs) = 81; goto _test_eof; 
	_test_eof82: ( parser->cs) = 82; goto _test_eof; 
	_test_eof83: ( parser->cs) = 83; goto _test_eof; 
	_test_eof84: ( parser->cs) = 84; goto _test_eof; 
	_test_eof85: ( parser->cs) = 85; goto _test_eof; 
	_test_eof86: ( parser->cs) = 86; goto _test_eof; 
	_test_eof87: ( parser->cs) = 87; goto _test_eof; 
	_test_eof88: ( parser->cs) = 88; goto _test_eof; 
	_test_eof89: ( parser->cs) = 89; goto _test_eof; 
	_test_eof90: ( parser->cs) = 90; goto _test_eof; 
	_test_eof634: ( parser->cs) = 634; goto _test_eof; 
	_test_eof91: ( parser->cs) = 91; goto _test_eof; 
	_test_eof92: ( parser->cs) = 92; goto _test_eof; 
	_test_eof93: ( parser->cs) = 93; goto _test_eof; 
	_test_eof94: ( parser->cs) = 94; goto _test_eof; 
	_test_eof95: ( parser->cs) = 95; goto _test_eof; 
	_test_eof96: ( parser->cs) = 96; goto _test_eof; 
	_test_eof97: ( parser->cs) = 97; goto _test_eof; 
	_test_eof635: ( parser->cs) = 635; goto _test_eof; 
	_test_eof98: ( parser->cs) = 98; goto _test_eof; 
	_test_eof99: ( parser->cs) = 99; goto _test_eof; 
	_test_eof100: ( parser->cs) = 100; goto _test_eof; 
	_test_eof101: ( parser->cs) = 101; goto _test_eof; 
	_test_eof102: ( parser->cs) = 102; goto _test_eof; 
	_test_eof103: ( parser->cs) = 103; goto _test_eof; 
	_test_eof636: ( parser->cs) = 636; goto _test_eof; 
	_test_eof104: ( parser->cs) = 104; goto _test_eof; 
	_test_eof105: ( parser->cs) = 105; goto _test_eof; 
	_test_eof106: ( parser->cs) = 106; goto _test_eof; 
	_test_eof107: ( parser->cs) = 107; goto _test_eof; 
	_test_eof108: ( parser->cs) = 108; goto _test_eof; 
	_test_eof637: ( parser->cs) = 637; goto _test_eof; 
	_test_eof109: ( parser->cs) = 109; goto _test_eof; 
	_test_eof110: ( parser->cs) = 110; goto _test_eof; 
	_test_eof111: ( parser->cs) = 111; goto _test_eof; 
	_test_eof112: ( parser->cs) = 112; goto _test_eof; 
	_test_eof113: ( parser->cs) = 113; goto _test_eof; 
	_test_eof114: ( parser->cs) = 114; goto _test_eof; 
	_test_eof115: ( parser->cs) = 115; goto _test_eof; 
	_test_eof116: ( parser->cs) = 116; goto _test_eof; 
	_test_eof117: ( parser->cs) = 117; goto _test_eof; 
	_test_eof118: ( parser->cs) = 118; goto _test_eof; 
	_test_eof119: ( parser->cs) = 119; goto _test_eof; 
	_test_eof638: ( parser->cs) = 638; goto _test_eof; 
	_test_eof120: ( parser->cs) = 120; goto _test_eof; 
	_test_eof121: ( parser->cs) = 121; goto _test_eof; 
	_test_eof639: ( parser->cs) = 639; goto _test_eof; 
	_test_eof122: ( parser->cs) = 122; goto _test_eof; 
	_test_eof123: ( parser->cs) = 123; goto _test_eof; 
	_test_eof124: ( parser->cs) = 124; goto _test_eof; 
	_test_eof125: ( parser->cs) = 125; goto _test_eof; 
	_test_eof126: ( parser->cs) = 126; goto _test_eof; 
	_test_eof127: ( parser->cs) = 127; goto _test_eof; 
	_test_eof128: ( parser->cs) = 128; goto _test_eof; 
	_test_eof129: ( parser->cs) = 129; goto _test_eof; 
	_test_eof130: ( parser->cs) = 130; goto _test_eof; 
	_test_eof131: ( parser->cs) = 131; goto _test_eof; 
	_test_eof132: ( parser->cs) = 132; goto _test_eof; 
	_test_eof133: ( parser->cs) = 133; goto _test_eof; 
	_test_eof134: ( parser->cs) = 134; goto _test_eof; 
	_test_eof135: ( parser->cs) = 135; goto _test_eof; 
	_test_eof136: ( parser->cs) = 136; goto _test_eof; 
	_test_eof137: ( parser->cs) = 137; goto _test_eof; 
	_test_eof138: ( parser->cs) = 138; goto _test_eof; 
	_test_eof640: ( parser->cs) = 640; goto _test_eof; 
	_test_eof139: ( parser->cs) = 139; goto _test_eof; 
	_test_eof140: ( parser->cs) = 140; goto _test_eof; 
	_test_eof141: ( parser->cs) = 141; goto _test_eof; 
	_test_eof142: ( parser->cs) = 142; goto _test_eof; 
	_test_eof143: ( parser->cs) = 143; goto _test_eof; 
	_test_eof144: ( parser->cs) = 144; goto _test_eof; 
	_test_eof641: ( parser->cs) = 641; goto _test_eof; 
	_test_eof145: ( parser->cs) = 145; goto _test_eof; 
	_test_eof146: ( parser->cs) = 146; goto _test_eof; 
	_test_eof147: ( parser->cs) = 147; goto _test_eof; 
	_test_eof148: ( parser->cs) = 148; goto _test_eof; 
	_test_eof149: ( parser->cs) = 149; goto _test_eof; 
	_test_eof150: ( parser->cs) = 150; goto _test_eof; 
	_test_eof642: ( parser->cs) = 642; goto _test_eof; 
	_test_eof151: ( parser->cs) = 151; goto _test_eof; 
	_test_eof152: ( parser->cs) = 152; goto _test_eof; 
	_test_eof153: ( parser->cs) = 153; goto _test_eof; 
	_test_eof154: ( parser->cs) = 154; goto _test_eof; 
	_test_eof155: ( parser->cs) = 155; goto _test_eof; 
	_test_eof156: ( parser->cs) = 156; goto _test_eof; 
	_test_eof157: ( parser->cs) = 157; goto _test_eof; 
	_test_eof158: ( parser->cs) = 158; goto _test_eof; 
	_test_eof159: ( parser->cs) = 159; goto _test_eof; 
	_test_eof160: ( parser->cs) = 160; goto _test_eof; 
	_test_eof643: ( parser->cs) = 643; goto _test_eof; 
	_test_eof161: ( parser->cs) = 161; goto _test_eof; 
	_test_eof162: ( parser->cs) = 162; goto _test_eof; 
	_test_eof163: ( parser->cs) = 163; goto _test_eof; 
	_test_eof164: ( parser->cs) = 164; goto _test_eof; 
	_test_eof165: ( parser->cs) = 165; goto _test_eof; 
	_test_eof644: ( parser->cs) = 644; goto _test_eof; 
	_test_eof645: ( parser->cs) = 645; goto _test_eof; 
	_test_eof646: ( parser->cs) = 646; goto _test_eof; 
	_test_eof166: ( parser->cs) = 166; goto _test_eof; 
	_test_eof167: ( parser->cs) = 167; goto _test_eof; 
	_test_eof647: ( parser->cs) = 647; goto _test_eof; 
	_test_eof168: ( parser->cs) = 168; goto _test_eof; 
	_test_eof169: ( parser->cs) = 169; goto _test_eof; 
	_test_eof170: ( parser->cs) = 170; goto _test_eof; 
	_test_eof171: ( parser->cs) = 171; goto _test_eof; 
	_test_eof172: ( parser->cs) = 172; goto _test_eof; 
	_test_eof173: ( parser->cs) = 173; goto _test_eof; 
	_test_eof174: ( parser->cs) = 174; goto _test_eof; 
	_test_eof175: ( parser->cs) = 175; goto _test_eof; 
	_test_eof176: ( parser->cs) = 176; goto _test_eof; 
	_test_eof648: ( parser->cs) = 648; goto _test_eof; 
	_test_eof177: ( parser->cs) = 177; goto _test_eof; 
	_test_eof178: ( parser->cs) = 178; goto _test_eof; 
	_test_eof179: ( parser->cs) = 179; goto _test_eof; 
	_test_eof180: ( parser->cs) = 180; goto _test_eof; 
	_test_eof181: ( parser->cs) = 181; goto _test_eof; 
	_test_eof649: ( parser->cs) = 649; goto _test_eof; 
	_test_eof650: ( parser->cs) = 650; goto _test_eof; 
	_test_eof651: ( parser->cs) = 651; goto _test_eof; 
	_test_eof182: ( parser->cs) = 182; goto _test_eof; 
	_test_eof183: ( parser->cs) = 183; goto _test_eof; 
	_test_eof184: ( parser->cs) = 184; goto _test_eof; 
	_test_eof185: ( parser->cs) = 185; goto _test_eof; 
	_test_eof186: ( parser->cs) = 186; goto _test_eof; 
	_test_eof187: ( parser->cs) = 187; goto _test_eof; 
	_test_eof188: ( parser->cs) = 188; goto _test_eof; 
	_test_eof189: ( parser->cs) = 189; goto _test_eof; 
	_test_eof190: ( parser->cs) = 190; goto _test_eof; 
	_test_eof191: ( parser->cs) = 191; goto _test_eof; 
	_test_eof192: ( parser->cs) = 192; goto _test_eof; 
	_test_eof193: ( parser->cs) = 193; goto _test_eof; 
	_test_eof194: ( parser->cs) = 194; goto _test_eof; 
	_test_eof195: ( parser->cs) = 195; goto _test_eof; 
	_test_eof196: ( parser->cs) = 196; goto _test_eof; 
	_test_eof197: ( parser->cs) = 197; goto _test_eof; 
	_test_eof198: ( parser->cs) = 198; goto _test_eof; 
	_test_eof199: ( parser->cs) = 199; goto _test_eof; 
	_test_eof200: ( parser->cs) = 200; goto _test_eof; 
	_test_eof201: ( parser->cs) = 201; goto _test_eof; 
	_test_eof202: ( parser->cs) = 202; goto _test_eof; 
	_test_eof203: ( parser->cs) = 203; goto _test_eof; 
	_test_eof204: ( parser->cs) = 204; goto _test_eof; 
	_test_eof205: ( parser->cs) = 205; goto _test_eof; 
	_test_eof206: ( parser->cs) = 206; goto _test_eof; 
	_test_eof207: ( parser->cs) = 207; goto _test_eof; 
	_test_eof208: ( parser->cs) = 208; goto _test_eof; 
	_test_eof209: ( parser->cs) = 209; goto _test_eof; 
	_test_eof210: ( parser->cs) = 210; goto _test_eof; 
	_test_eof652: ( parser->cs) = 652; goto _test_eof; 
	_test_eof211: ( parser->cs) = 211; goto _test_eof; 
	_test_eof212: ( parser->cs) = 212; goto _test_eof; 
	_test_eof213: ( parser->cs) = 213; goto _test_eof; 
	_test_eof214: ( parser->cs) = 214; goto _test_eof; 
	_test_eof215: ( parser->cs) = 215; goto _test_eof; 
	_test_eof216: ( parser->cs) = 216; goto _test_eof; 
	_test_eof217: ( parser->cs) = 217; goto _test_eof; 
	_test_eof218: ( parser->cs) = 218; goto _test_eof; 
	_test_eof219: ( parser->cs) = 219; goto _test_eof; 
	_test_eof220: ( parser->cs) = 220; goto _test_eof; 
	_test_eof221: ( parser->cs) = 221; goto _test_eof; 
	_test_eof222: ( parser->cs) = 222; goto _test_eof; 
	_test_eof223: ( parser->cs) = 223; goto _test_eof; 
	_test_eof224: ( parser->cs) = 224; goto _test_eof; 
	_test_eof225: ( parser->cs) = 225; goto _test_eof; 
	_test_eof226: ( parser->cs) = 226; goto _test_eof; 
	_test_eof227: ( parser->cs) = 227; goto _test_eof; 
	_test_eof228: ( parser->cs) = 228; goto _test_eof; 
	_test_eof229: ( parser->cs) = 229; goto _test_eof; 
	_test_eof230: ( parser->cs) = 230; goto _test_eof; 
	_test_eof653: ( parser->cs) = 653; goto _test_eof; 
	_test_eof231: ( parser->cs) = 231; goto _test_eof; 
	_test_eof232: ( parser->cs) = 232; goto _test_eof; 
	_test_eof233: ( parser->cs) = 233; goto _test_eof; 
	_test_eof234: ( parser->cs) = 234; goto _test_eof; 
	_test_eof235: ( parser->cs) = 235; goto _test_eof; 
	_test_eof236: ( parser->cs) = 236; goto _test_eof; 
	_test_eof237: ( parser->cs) = 237; goto _test_eof; 
	_test_eof238: ( parser->cs) = 238; goto _test_eof; 
	_test_eof239: ( parser->cs) = 239; goto _test_eof; 
	_test_eof240: ( parser->cs) = 240; goto _test_eof; 
	_test_eof654: ( parser->cs) = 654; goto _test_eof; 
	_test_eof241: ( parser->cs) = 241; goto _test_eof; 
	_test_eof242: ( parser->cs) = 242; goto _test_eof; 
	_test_eof243: ( parser->cs) = 243; goto _test_eof; 
	_test_eof244: ( parser->cs) = 244; goto _test_eof; 
	_test_eof245: ( parser->cs) = 245; goto _test_eof; 
	_test_eof246: ( parser->cs) = 246; goto _test_eof; 
	_test_eof247: ( parser->cs) = 247; goto _test_eof; 
	_test_eof248: ( parser->cs) = 248; goto _test_eof; 
	_test_eof249: ( parser->cs) = 249; goto _test_eof; 
	_test_eof250: ( parser->cs) = 250; goto _test_eof; 
	_test_eof251: ( parser->cs) = 251; goto _test_eof; 
	_test_eof252: ( parser->cs) = 252; goto _test_eof; 
	_test_eof253: ( parser->cs) = 253; goto _test_eof; 
	_test_eof254: ( parser->cs) = 254; goto _test_eof; 
	_test_eof255: ( parser->cs) = 255; goto _test_eof; 
	_test_eof256: ( parser->cs) = 256; goto _test_eof; 
	_test_eof257: ( parser->cs) = 257; goto _test_eof; 
	_test_eof258: ( parser->cs) = 258; goto _test_eof; 
	_test_eof259: ( parser->cs) = 259; goto _test_eof; 
	_test_eof260: ( parser->cs) = 260; goto _test_eof; 
	_test_eof261: ( parser->cs) = 261; goto _test_eof; 
	_test_eof262: ( parser->cs) = 262; goto _test_eof; 
	_test_eof655: ( parser->cs) = 655; goto _test_eof; 
	_test_eof263: ( parser->cs) = 263; goto _test_eof; 
	_test_eof264: ( parser->cs) = 264; goto _test_eof; 
	_test_eof265: ( parser->cs) = 265; goto _test_eof; 
	_test_eof266: ( parser->cs) = 266; goto _test_eof; 
	_test_eof267: ( parser->cs) = 267; goto _test_eof; 
	_test_eof268: ( parser->cs) = 268; goto _test_eof; 
	_test_eof269: ( parser->cs) = 269; goto _test_eof; 
	_test_eof270: ( parser->cs) = 270; goto _test_eof; 
	_test_eof271: ( parser->cs) = 271; goto _test_eof; 
	_test_eof272: ( parser->cs) = 272; goto _test_eof; 
	_test_eof273: ( parser->cs) = 273; goto _test_eof; 
	_test_eof274: ( parser->cs) = 274; goto _test_eof; 
	_test_eof656: ( parser->cs) = 656; goto _test_eof; 
	_test_eof275: ( parser->cs) = 275; goto _test_eof; 
	_test_eof276: ( parser->cs) = 276; goto _test_eof; 
	_test_eof277: ( parser->cs) = 277; goto _test_eof; 
	_test_eof278: ( parser->cs) = 278; goto _test_eof; 
	_test_eof279: ( parser->cs) = 279; goto _test_eof; 
	_test_eof657: ( parser->cs) = 657; goto _test_eof; 
	_test_eof280: ( parser->cs) = 280; goto _test_eof; 
	_test_eof281: ( parser->cs) = 281; goto _test_eof; 
	_test_eof282: ( parser->cs) = 282; goto _test_eof; 
	_test_eof283: ( parser->cs) = 283; goto _test_eof; 
	_test_eof658: ( parser->cs) = 658; goto _test_eof; 
	_test_eof284: ( parser->cs) = 284; goto _test_eof; 
	_test_eof285: ( parser->cs) = 285; goto _test_eof; 
	_test_eof659: ( parser->cs) = 659; goto _test_eof; 
	_test_eof286: ( parser->cs) = 286; goto _test_eof; 
	_test_eof287: ( parser->cs) = 287; goto _test_eof; 
	_test_eof288: ( parser->cs) = 288; goto _test_eof; 
	_test_eof289: ( parser->cs) = 289; goto _test_eof; 
	_test_eof290: ( parser->cs) = 290; goto _test_eof; 
	_test_eof291: ( parser->cs) = 291; goto _test_eof; 
	_test_eof292: ( parser->cs) = 292; goto _test_eof; 
	_test_eof293: ( parser->cs) = 293; goto _test_eof; 
	_test_eof294: ( parser->cs) = 294; goto _test_eof; 
	_test_eof295: ( parser->cs) = 295; goto _test_eof; 
	_test_eof296: ( parser->cs) = 296; goto _test_eof; 
	_test_eof660: ( parser->cs) = 660; goto _test_eof; 
	_test_eof297: ( parser->cs) = 297; goto _test_eof; 
	_test_eof298: ( parser->cs) = 298; goto _test_eof; 
	_test_eof299: ( parser->cs) = 299; goto _test_eof; 
	_test_eof300: ( parser->cs) = 300; goto _test_eof; 
	_test_eof301: ( parser->cs) = 301; goto _test_eof; 
	_test_eof661: ( parser->cs) = 661; goto _test_eof; 
	_test_eof662: ( parser->cs) = 662; goto _test_eof; 
	_test_eof302: ( parser->cs) = 302; goto _test_eof; 
	_test_eof303: ( parser->cs) = 303; goto _test_eof; 
	_test_eof304: ( parser->cs) = 304; goto _test_eof; 
	_test_eof305: ( parser->cs) = 305; goto _test_eof; 
	_test_eof306: ( parser->cs) = 306; goto _test_eof; 
	_test_eof307: ( parser->cs) = 307; goto _test_eof; 
	_test_eof308: ( parser->cs) = 308; goto _test_eof; 
	_test_eof309: ( parser->cs) = 309; goto _test_eof; 
	_test_eof310: ( parser->cs) = 310; goto _test_eof; 
	_test_eof311: ( parser->cs) = 311; goto _test_eof; 
	_test_eof312: ( parser->cs) = 312; goto _test_eof; 
	_test_eof313: ( parser->cs) = 313; goto _test_eof; 
	_test_eof314: ( parser->cs) = 314; goto _test_eof; 
	_test_eof663: ( parser->cs) = 663; goto _test_eof; 
	_test_eof315: ( parser->cs) = 315; goto _test_eof; 
	_test_eof316: ( parser->cs) = 316; goto _test_eof; 
	_test_eof317: ( parser->cs) = 317; goto _test_eof; 
	_test_eof318: ( parser->cs) = 318; goto _test_eof; 
	_test_eof319: ( parser->cs) = 319; goto _test_eof; 
	_test_eof320: ( parser->cs) = 320; goto _test_eof; 
	_test_eof321: ( parser->cs) = 321; goto _test_eof; 
	_test_eof322: ( parser->cs) = 322; goto _test_eof; 
	_test_eof323: ( parser->cs) = 323; goto _test_eof; 
	_test_eof324: ( parser->cs) = 324; goto _test_eof; 
	_test_eof325: ( parser->cs) = 325; goto _test_eof; 
	_test_eof326: ( parser->cs) = 326; goto _test_eof; 
	_test_eof327: ( parser->cs) = 327; goto _test_eof; 
	_test_eof664: ( parser->cs) = 664; goto _test_eof; 
	_test_eof328: ( parser->cs) = 328; goto _test_eof; 
	_test_eof329: ( parser->cs) = 329; goto _test_eof; 
	_test_eof330: ( parser->cs) = 330; goto _test_eof; 
	_test_eof331: ( parser->cs) = 331; goto _test_eof; 
	_test_eof332: ( parser->cs) = 332; goto _test_eof; 
	_test_eof333: ( parser->cs) = 333; goto _test_eof; 
	_test_eof334: ( parser->cs) = 334; goto _test_eof; 
	_test_eof335: ( parser->cs) = 335; goto _test_eof; 
	_test_eof336: ( parser->cs) = 336; goto _test_eof; 
	_test_eof337: ( parser->cs) = 337; goto _test_eof; 
	_test_eof338: ( parser->cs) = 338; goto _test_eof; 
	_test_eof339: ( parser->cs) = 339; goto _test_eof; 
	_test_eof340: ( parser->cs) = 340; goto _test_eof; 
	_test_eof341: ( parser->cs) = 341; goto _test_eof; 
	_test_eof342: ( parser->cs) = 342; goto _test_eof; 
	_test_eof343: ( parser->cs) = 343; goto _test_eof; 
	_test_eof344: ( parser->cs) = 344; goto _test_eof; 
	_test_eof345: ( parser->cs) = 345; goto _test_eof; 
	_test_eof346: ( parser->cs) = 346; goto _test_eof; 
	_test_eof347: ( parser->cs) = 347; goto _test_eof; 
	_test_eof348: ( parser->cs) = 348; goto _test_eof; 
	_test_eof349: ( parser->cs) = 349; goto _test_eof; 
	_test_eof665: ( parser->cs) = 665; goto _test_eof; 
	_test_eof350: ( parser->cs) = 350; goto _test_eof; 
	_test_eof351: ( parser->cs) = 351; goto _test_eof; 
	_test_eof352: ( parser->cs) = 352; goto _test_eof; 
	_test_eof353: ( parser->cs) = 353; goto _test_eof; 
	_test_eof354: ( parser->cs) = 354; goto _test_eof; 
	_test_eof666: ( parser->cs) = 666; goto _test_eof; 
	_test_eof355: ( parser->cs) = 355; goto _test_eof; 
	_test_eof356: ( parser->cs) = 356; goto _test_eof; 
	_test_eof357: ( parser->cs) = 357; goto _test_eof; 
	_test_eof358: ( parser->cs) = 358; goto _test_eof; 
	_test_eof359: ( parser->cs) = 359; goto _test_eof; 
	_test_eof360: ( parser->cs) = 360; goto _test_eof; 
	_test_eof361: ( parser->cs) = 361; goto _test_eof; 
	_test_eof667: ( parser->cs) = 667; goto _test_eof; 
	_test_eof362: ( parser->cs) = 362; goto _test_eof; 
	_test_eof363: ( parser->cs) = 363; goto _test_eof; 
	_test_eof364: ( parser->cs) = 364; goto _test_eof; 
	_test_eof365: ( parser->cs) = 365; goto _test_eof; 
	_test_eof366: ( parser->cs) = 366; goto _test_eof; 
	_test_eof367: ( parser->cs) = 367; goto _test_eof; 
	_test_eof668: ( parser->cs) = 668; goto _test_eof; 
	_test_eof368: ( parser->cs) = 368; goto _test_eof; 
	_test_eof369: ( parser->cs) = 369; goto _test_eof; 
	_test_eof370: ( parser->cs) = 370; goto _test_eof; 
	_test_eof371: ( parser->cs) = 371; goto _test_eof; 
	_test_eof372: ( parser->cs) = 372; goto _test_eof; 
	_test_eof373: ( parser->cs) = 373; goto _test_eof; 
	_test_eof669: ( parser->cs) = 669; goto _test_eof; 
	_test_eof374: ( parser->cs) = 374; goto _test_eof; 
	_test_eof375: ( parser->cs) = 375; goto _test_eof; 
	_test_eof376: ( parser->cs) = 376; goto _test_eof; 
	_test_eof377: ( parser->cs) = 377; goto _test_eof; 
	_test_eof378: ( parser->cs) = 378; goto _test_eof; 
	_test_eof379: ( parser->cs) = 379; goto _test_eof; 
	_test_eof380: ( parser->cs) = 380; goto _test_eof; 
	_test_eof381: ( parser->cs) = 381; goto _test_eof; 
	_test_eof382: ( parser->cs) = 382; goto _test_eof; 
	_test_eof383: ( parser->cs) = 383; goto _test_eof; 
	_test_eof670: ( parser->cs) = 670; goto _test_eof; 
	_test_eof384: ( parser->cs) = 384; goto _test_eof; 
	_test_eof385: ( parser->cs) = 385; goto _test_eof; 
	_test_eof386: ( parser->cs) = 386; goto _test_eof; 
	_test_eof387: ( parser->cs) = 387; goto _test_eof; 
	_test_eof388: ( parser->cs) = 388; goto _test_eof; 
	_test_eof671: ( parser->cs) = 671; goto _test_eof; 
	_test_eof672: ( parser->cs) = 672; goto _test_eof; 
	_test_eof389: ( parser->cs) = 389; goto _test_eof; 
	_test_eof390: ( parser->cs) = 390; goto _test_eof; 
	_test_eof391: ( parser->cs) = 391; goto _test_eof; 
	_test_eof392: ( parser->cs) = 392; goto _test_eof; 
	_test_eof393: ( parser->cs) = 393; goto _test_eof; 
	_test_eof394: ( parser->cs) = 394; goto _test_eof; 
	_test_eof395: ( parser->cs) = 395; goto _test_eof; 
	_test_eof396: ( parser->cs) = 396; goto _test_eof; 
	_test_eof397: ( parser->cs) = 397; goto _test_eof; 
	_test_eof398: ( parser->cs) = 398; goto _test_eof; 
	_test_eof399: ( parser->cs) = 399; goto _test_eof; 
	_test_eof400: ( parser->cs) = 400; goto _test_eof; 
	_test_eof401: ( parser->cs) = 401; goto _test_eof; 
	_test_eof673: ( parser->cs) = 673; goto _test_eof; 
	_test_eof402: ( parser->cs) = 402; goto _test_eof; 
	_test_eof403: ( parser->cs) = 403; goto _test_eof; 
	_test_eof404: ( parser->cs) = 404; goto _test_eof; 
	_test_eof405: ( parser->cs) = 405; goto _test_eof; 
	_test_eof406: ( parser->cs) = 406; goto _test_eof; 
	_test_eof407: ( parser->cs) = 407; goto _test_eof; 
	_test_eof408: ( parser->cs) = 408; goto _test_eof; 
	_test_eof409: ( parser->cs) = 409; goto _test_eof; 
	_test_eof410: ( parser->cs) = 410; goto _test_eof; 
	_test_eof411: ( parser->cs) = 411; goto _test_eof; 
	_test_eof412: ( parser->cs) = 412; goto _test_eof; 
	_test_eof413: ( parser->cs) = 413; goto _test_eof; 
	_test_eof414: ( parser->cs) = 414; goto _test_eof; 
	_test_eof674: ( parser->cs) = 674; goto _test_eof; 
	_test_eof415: ( parser->cs) = 415; goto _test_eof; 
	_test_eof416: ( parser->cs) = 416; goto _test_eof; 
	_test_eof417: ( parser->cs) = 417; goto _test_eof; 
	_test_eof418: ( parser->cs) = 418; goto _test_eof; 
	_test_eof419: ( parser->cs) = 419; goto _test_eof; 
	_test_eof420: ( parser->cs) = 420; goto _test_eof; 
	_test_eof421: ( parser->cs) = 421; goto _test_eof; 
	_test_eof422: ( parser->cs) = 422; goto _test_eof; 
	_test_eof423: ( parser->cs) = 423; goto _test_eof; 
	_test_eof424: ( parser->cs) = 424; goto _test_eof; 
	_test_eof425: ( parser->cs) = 425; goto _test_eof; 
	_test_eof426: ( parser->cs) = 426; goto _test_eof; 
	_test_eof427: ( parser->cs) = 427; goto _test_eof; 
	_test_eof428: ( parser->cs) = 428; goto _test_eof; 
	_test_eof429: ( parser->cs) = 429; goto _test_eof; 
	_test_eof430: ( parser->cs) = 430; goto _test_eof; 
	_test_eof431: ( parser->cs) = 431; goto _test_eof; 
	_test_eof432: ( parser->cs) = 432; goto _test_eof; 
	_test_eof433: ( parser->cs) = 433; goto _test_eof; 
	_test_eof434: ( parser->cs) = 434; goto _test_eof; 
	_test_eof675: ( parser->cs) = 675; goto _test_eof; 
	_test_eof435: ( parser->cs) = 435; goto _test_eof; 
	_test_eof436: ( parser->cs) = 436; goto _test_eof; 
	_test_eof437: ( parser->cs) = 437; goto _test_eof; 
	_test_eof438: ( parser->cs) = 438; goto _test_eof; 
	_test_eof439: ( parser->cs) = 439; goto _test_eof; 
	_test_eof440: ( parser->cs) = 440; goto _test_eof; 
	_test_eof441: ( parser->cs) = 441; goto _test_eof; 
	_test_eof442: ( parser->cs) = 442; goto _test_eof; 
	_test_eof443: ( parser->cs) = 443; goto _test_eof; 
	_test_eof444: ( parser->cs) = 444; goto _test_eof; 
	_test_eof676: ( parser->cs) = 676; goto _test_eof; 
	_test_eof445: ( parser->cs) = 445; goto _test_eof; 
	_test_eof446: ( parser->cs) = 446; goto _test_eof; 
	_test_eof447: ( parser->cs) = 447; goto _test_eof; 
	_test_eof448: ( parser->cs) = 448; goto _test_eof; 
	_test_eof449: ( parser->cs) = 449; goto _test_eof; 
	_test_eof450: ( parser->cs) = 450; goto _test_eof; 
	_test_eof451: ( parser->cs) = 451; goto _test_eof; 
	_test_eof452: ( parser->cs) = 452; goto _test_eof; 
	_test_eof453: ( parser->cs) = 453; goto _test_eof; 
	_test_eof454: ( parser->cs) = 454; goto _test_eof; 
	_test_eof455: ( parser->cs) = 455; goto _test_eof; 
	_test_eof456: ( parser->cs) = 456; goto _test_eof; 
	_test_eof457: ( parser->cs) = 457; goto _test_eof; 
	_test_eof458: ( parser->cs) = 458; goto _test_eof; 
	_test_eof459: ( parser->cs) = 459; goto _test_eof; 
	_test_eof460: ( parser->cs) = 460; goto _test_eof; 
	_test_eof461: ( parser->cs) = 461; goto _test_eof; 
	_test_eof462: ( parser->cs) = 462; goto _test_eof; 
	_test_eof463: ( parser->cs) = 463; goto _test_eof; 
	_test_eof464: ( parser->cs) = 464; goto _test_eof; 
	_test_eof465: ( parser->cs) = 465; goto _test_eof; 
	_test_eof466: ( parser->cs) = 466; goto _test_eof; 
	_test_eof677: ( parser->cs) = 677; goto _test_eof; 
	_test_eof467: ( parser->cs) = 467; goto _test_eof; 
	_test_eof468: ( parser->cs) = 468; goto _test_eof; 
	_test_eof469: ( parser->cs) = 469; goto _test_eof; 
	_test_eof470: ( parser->cs) = 470; goto _test_eof; 
	_test_eof471: ( parser->cs) = 471; goto _test_eof; 
	_test_eof678: ( parser->cs) = 678; goto _test_eof; 
	_test_eof472: ( parser->cs) = 472; goto _test_eof; 
	_test_eof473: ( parser->cs) = 473; goto _test_eof; 
	_test_eof474: ( parser->cs) = 474; goto _test_eof; 
	_test_eof475: ( parser->cs) = 475; goto _test_eof; 
	_test_eof476: ( parser->cs) = 476; goto _test_eof; 
	_test_eof477: ( parser->cs) = 477; goto _test_eof; 
	_test_eof478: ( parser->cs) = 478; goto _test_eof; 
	_test_eof679: ( parser->cs) = 679; goto _test_eof; 
	_test_eof479: ( parser->cs) = 479; goto _test_eof; 
	_test_eof480: ( parser->cs) = 480; goto _test_eof; 
	_test_eof481: ( parser->cs) = 481; goto _test_eof; 
	_test_eof482: ( parser->cs) = 482; goto _test_eof; 
	_test_eof483: ( parser->cs) = 483; goto _test_eof; 
	_test_eof484: ( parser->cs) = 484; goto _test_eof; 
	_test_eof680: ( parser->cs) = 680; goto _test_eof; 
	_test_eof485: ( parser->cs) = 485; goto _test_eof; 
	_test_eof486: ( parser->cs) = 486; goto _test_eof; 
	_test_eof487: ( parser->cs) = 487; goto _test_eof; 
	_test_eof488: ( parser->cs) = 488; goto _test_eof; 
	_test_eof489: ( parser->cs) = 489; goto _test_eof; 
	_test_eof490: ( parser->cs) = 490; goto _test_eof; 
	_test_eof681: ( parser->cs) = 681; goto _test_eof; 
	_test_eof491: ( parser->cs) = 491; goto _test_eof; 
	_test_eof492: ( parser->cs) = 492; goto _test_eof; 
	_test_eof493: ( parser->cs) = 493; goto _test_eof; 
	_test_eof494: ( parser->cs) = 494; goto _test_eof; 
	_test_eof495: ( parser->cs) = 495; goto _test_eof; 
	_test_eof496: ( parser->cs) = 496; goto _test_eof; 
	_test_eof497: ( parser->cs) = 497; goto _test_eof; 
	_test_eof498: ( parser->cs) = 498; goto _test_eof; 
	_test_eof499: ( parser->cs) = 499; goto _test_eof; 
	_test_eof500: ( parser->cs) = 500; goto _test_eof; 
	_test_eof682: ( parser->cs) = 682; goto _test_eof; 
	_test_eof501: ( parser->cs) = 501; goto _test_eof; 
	_test_eof502: ( parser->cs) = 502; goto _test_eof; 
	_test_eof503: ( parser->cs) = 503; goto _test_eof; 
	_test_eof504: ( parser->cs) = 504; goto _test_eof; 
	_test_eof505: ( parser->cs) = 505; goto _test_eof; 
	_test_eof683: ( parser->cs) = 683; goto _test_eof; 
	_test_eof684: ( parser->cs) = 684; goto _test_eof; 
	_test_eof506: ( parser->cs) = 506; goto _test_eof; 
	_test_eof507: ( parser->cs) = 507; goto _test_eof; 
	_test_eof508: ( parser->cs) = 508; goto _test_eof; 
	_test_eof509: ( parser->cs) = 509; goto _test_eof; 
	_test_eof510: ( parser->cs) = 510; goto _test_eof; 
	_test_eof511: ( parser->cs) = 511; goto _test_eof; 
	_test_eof512: ( parser->cs) = 512; goto _test_eof; 
	_test_eof513: ( parser->cs) = 513; goto _test_eof; 
	_test_eof514: ( parser->cs) = 514; goto _test_eof; 
	_test_eof515: ( parser->cs) = 515; goto _test_eof; 
	_test_eof516: ( parser->cs) = 516; goto _test_eof; 
	_test_eof517: ( parser->cs) = 517; goto _test_eof; 
	_test_eof518: ( parser->cs) = 518; goto _test_eof; 
	_test_eof685: ( parser->cs) = 685; goto _test_eof; 
	_test_eof519: ( parser->cs) = 519; goto _test_eof; 
	_test_eof520: ( parser->cs) = 520; goto _test_eof; 
	_test_eof521: ( parser->cs) = 521; goto _test_eof; 
	_test_eof522: ( parser->cs) = 522; goto _test_eof; 
	_test_eof523: ( parser->cs) = 523; goto _test_eof; 
	_test_eof524: ( parser->cs) = 524; goto _test_eof; 
	_test_eof525: ( parser->cs) = 525; goto _test_eof; 
	_test_eof526: ( parser->cs) = 526; goto _test_eof; 
	_test_eof527: ( parser->cs) = 527; goto _test_eof; 
	_test_eof528: ( parser->cs) = 528; goto _test_eof; 
	_test_eof529: ( parser->cs) = 529; goto _test_eof; 
	_test_eof530: ( parser->cs) = 530; goto _test_eof; 
	_test_eof531: ( parser->cs) = 531; goto _test_eof; 
	_test_eof686: ( parser->cs) = 686; goto _test_eof; 
	_test_eof532: ( parser->cs) = 532; goto _test_eof; 
	_test_eof533: ( parser->cs) = 533; goto _test_eof; 
	_test_eof534: ( parser->cs) = 534; goto _test_eof; 
	_test_eof535: ( parser->cs) = 535; goto _test_eof; 
	_test_eof536: ( parser->cs) = 536; goto _test_eof; 
	_test_eof537: ( parser->cs) = 537; goto _test_eof; 
	_test_eof538: ( parser->cs) = 538; goto _test_eof; 
	_test_eof539: ( parser->cs) = 539; goto _test_eof; 
	_test_eof540: ( parser->cs) = 540; goto _test_eof; 
	_test_eof541: ( parser->cs) = 541; goto _test_eof; 
	_test_eof542: ( parser->cs) = 542; goto _test_eof; 
	_test_eof543: ( parser->cs) = 543; goto _test_eof; 
	_test_eof544: ( parser->cs) = 544; goto _test_eof; 
	_test_eof545: ( parser->cs) = 545; goto _test_eof; 
	_test_eof546: ( parser->cs) = 546; goto _test_eof; 
	_test_eof547: ( parser->cs) = 547; goto _test_eof; 
	_test_eof548: ( parser->cs) = 548; goto _test_eof; 
	_test_eof549: ( parser->cs) = 549; goto _test_eof; 
	_test_eof550: ( parser->cs) = 550; goto _test_eof; 
	_test_eof551: ( parser->cs) = 551; goto _test_eof; 
	_test_eof552: ( parser->cs) = 552; goto _test_eof; 
	_test_eof553: ( parser->cs) = 553; goto _test_eof; 
	_test_eof687: ( parser->cs) = 687; goto _test_eof; 
	_test_eof554: ( parser->cs) = 554; goto _test_eof; 
	_test_eof555: ( parser->cs) = 555; goto _test_eof; 
	_test_eof556: ( parser->cs) = 556; goto _test_eof; 
	_test_eof557: ( parser->cs) = 557; goto _test_eof; 
	_test_eof558: ( parser->cs) = 558; goto _test_eof; 
	_test_eof688: ( parser->cs) = 688; goto _test_eof; 
	_test_eof559: ( parser->cs) = 559; goto _test_eof; 
	_test_eof560: ( parser->cs) = 560; goto _test_eof; 
	_test_eof561: ( parser->cs) = 561; goto _test_eof; 
	_test_eof562: ( parser->cs) = 562; goto _test_eof; 
	_test_eof563: ( parser->cs) = 563; goto _test_eof; 
	_test_eof564: ( parser->cs) = 564; goto _test_eof; 
	_test_eof565: ( parser->cs) = 565; goto _test_eof; 
	_test_eof689: ( parser->cs) = 689; goto _test_eof; 
	_test_eof566: ( parser->cs) = 566; goto _test_eof; 
	_test_eof567: ( parser->cs) = 567; goto _test_eof; 
	_test_eof568: ( parser->cs) = 568; goto _test_eof; 
	_test_eof569: ( parser->cs) = 569; goto _test_eof; 
	_test_eof570: ( parser->cs) = 570; goto _test_eof; 
	_test_eof571: ( parser->cs) = 571; goto _test_eof; 
	_test_eof690: ( parser->cs) = 690; goto _test_eof; 
	_test_eof572: ( parser->cs) = 572; goto _test_eof; 
	_test_eof573: ( parser->cs) = 573; goto _test_eof; 
	_test_eof574: ( parser->cs) = 574; goto _test_eof; 
	_test_eof575: ( parser->cs) = 575; goto _test_eof; 
	_test_eof576: ( parser->cs) = 576; goto _test_eof; 
	_test_eof577: ( parser->cs) = 577; goto _test_eof; 
	_test_eof691: ( parser->cs) = 691; goto _test_eof; 
	_test_eof578: ( parser->cs) = 578; goto _test_eof; 
	_test_eof579: ( parser->cs) = 579; goto _test_eof; 
	_test_eof580: ( parser->cs) = 580; goto _test_eof; 
	_test_eof581: ( parser->cs) = 581; goto _test_eof; 
	_test_eof582: ( parser->cs) = 582; goto _test_eof; 
	_test_eof583: ( parser->cs) = 583; goto _test_eof; 
	_test_eof584: ( parser->cs) = 584; goto _test_eof; 
	_test_eof585: ( parser->cs) = 585; goto _test_eof; 
	_test_eof586: ( parser->cs) = 586; goto _test_eof; 
	_test_eof587: ( parser->cs) = 587; goto _test_eof; 
	_test_eof692: ( parser->cs) = 692; goto _test_eof; 
	_test_eof588: ( parser->cs) = 588; goto _test_eof; 
	_test_eof589: ( parser->cs) = 589; goto _test_eof; 
	_test_eof590: ( parser->cs) = 590; goto _test_eof; 
	_test_eof591: ( parser->cs) = 591; goto _test_eof; 
	_test_eof592: ( parser->cs) = 592; goto _test_eof; 
	_test_eof693: ( parser->cs) = 693; goto _test_eof; 
	_test_eof694: ( parser->cs) = 694; goto _test_eof; 
	_test_eof593: ( parser->cs) = 593; goto _test_eof; 
	_test_eof594: ( parser->cs) = 594; goto _test_eof; 
	_test_eof595: ( parser->cs) = 595; goto _test_eof; 
	_test_eof596: ( parser->cs) = 596; goto _test_eof; 
	_test_eof597: ( parser->cs) = 597; goto _test_eof; 
	_test_eof598: ( parser->cs) = 598; goto _test_eof; 
	_test_eof599: ( parser->cs) = 599; goto _test_eof; 
	_test_eof600: ( parser->cs) = 600; goto _test_eof; 
	_test_eof601: ( parser->cs) = 601; goto _test_eof; 
	_test_eof602: ( parser->cs) = 602; goto _test_eof; 
	_test_eof603: ( parser->cs) = 603; goto _test_eof; 
	_test_eof604: ( parser->cs) = 604; goto _test_eof; 
	_test_eof605: ( parser->cs) = 605; goto _test_eof; 
	_test_eof695: ( parser->cs) = 695; goto _test_eof; 
	_test_eof606: ( parser->cs) = 606; goto _test_eof; 
	_test_eof607: ( parser->cs) = 607; goto _test_eof; 
	_test_eof608: ( parser->cs) = 608; goto _test_eof; 
	_test_eof609: ( parser->cs) = 609; goto _test_eof; 
	_test_eof610: ( parser->cs) = 610; goto _test_eof; 
	_test_eof611: ( parser->cs) = 611; goto _test_eof; 
	_test_eof612: ( parser->cs) = 612; goto _test_eof; 
	_test_eof613: ( parser->cs) = 613; goto _test_eof; 
	_test_eof696: ( parser->cs) = 696; goto _test_eof; 
	_test_eof614: ( parser->cs) = 614; goto _test_eof; 
	_test_eof615: ( parser->cs) = 615; goto _test_eof; 
	_test_eof616: ( parser->cs) = 616; goto _test_eof; 
	_test_eof697: ( parser->cs) = 697; goto _test_eof; 
	_test_eof617: ( parser->cs) = 617; goto _test_eof; 
	_test_eof618: ( parser->cs) = 618; goto _test_eof; 
	_test_eof698: ( parser->cs) = 698; goto _test_eof; 
	_test_eof619: ( parser->cs) = 619; goto _test_eof; 
	_test_eof620: ( parser->cs) = 620; goto _test_eof; 
	_test_eof621: ( parser->cs) = 621; goto _test_eof; 
	_test_eof622: ( parser->cs) = 622; goto _test_eof; 
	_test_eof623: ( parser->cs) = 623; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 175 "/home/xero/code/github.com/kJSON/src/kjson.rl"

    if (parser->cs == kjson_error) {
        return KJSON_ERROR_INVALID_JSON;
    }
    if (parser->cs < kjson_first_final) {
        return KJSON_ERROR_INVALID_JSON;
    }

    return KJSON_OK;
}
