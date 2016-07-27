#include "currency.h"

PG_MODULE_MAGIC;

static currency sort_map[] = {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  25,
  26,
  27,
  28,
  29,
  30,
  31,
  32,
  33,
  34,
  35,
  36,
  37,
  38,
  39,
  40,
  41,
  42,
  43,
  44,
  45,
  46,
  47,
  48,
  49,
  50,
  51,
  52,
  53,
  54,
  55,
  56,
  57,
  58,
  59,
  60,
  61,
  62,
  63,
  64,
  65,
  66,
  67,
  68,
  69,
  70,
  71,
  72,
  73,
  74,
  75,
  76,
  77,
  78,
  79,
  80,
  81,
  82,
  83,
  84,
  85,
  86,
  87,
  88,
  89,
  90,
  91,
  92,
  93,
  94,
  95,
  96,
  97,
  98,
  99,
  100,
  101,
  102,
  103,
  104,
  105,
  106,
  107,
  108,
  109,
  110,
  111,
  112,
  113,
  114,
  115,
  116,
  117,
  118,
  119,
  120,
  121,
  122,
  123,
  124,
  125,
  126,
  127,
  128,
  129,
  130,
  131,
  132,
  133,
  134,
  135,
  136,
  137,
  138,
  139,
  140,
  141,
  142,
  143,
  144,
  145,
  146,
  147,
  148,
  149,
  150,
  151,
  152,
  153,
  154,
  155,
  156,
  157,
  158,
  159,
  160,
  161,
  162,
  163,
  164,
  24
};

static int
currency_cmp_internal(currency a, currency b)
{
    return sort_map[a - 1] - sort_map[b - 1];
}

Datum
currency_in(PG_FUNCTION_ARGS)
{
    char *str = PG_GETARG_CSTRING(0);

    if (strlen(str) != 3)
        elog(ERROR, "invalid currency input string %s", str);

    switch (str[2] | str[1] << 8 | str[0] << 16)
    {
        case AED: PG_RETURN_CURRENCY(1);
        case AFN: PG_RETURN_CURRENCY(2);
        case ALL: PG_RETURN_CURRENCY(3);
        case AMD: PG_RETURN_CURRENCY(4);
        case ANG: PG_RETURN_CURRENCY(5);
        case AOA: PG_RETURN_CURRENCY(6);
        case ARS: PG_RETURN_CURRENCY(7);
        case AUD: PG_RETURN_CURRENCY(8);
        case AWG: PG_RETURN_CURRENCY(9);
        case AZN: PG_RETURN_CURRENCY(10);
        case BAM: PG_RETURN_CURRENCY(11);
        case BBD: PG_RETURN_CURRENCY(12);
        case BDT: PG_RETURN_CURRENCY(13);
        case BGN: PG_RETURN_CURRENCY(14);
        case BHD: PG_RETURN_CURRENCY(15);
        case BIF: PG_RETURN_CURRENCY(16);
        case BMD: PG_RETURN_CURRENCY(17);
        case BND: PG_RETURN_CURRENCY(18);
        case BOB: PG_RETURN_CURRENCY(19);
        case BRL: PG_RETURN_CURRENCY(20);
        case BSD: PG_RETURN_CURRENCY(21);
        case BTN: PG_RETURN_CURRENCY(22);
        case BWP: PG_RETURN_CURRENCY(23);
        case BYR: PG_RETURN_CURRENCY(24);
        case BZD: PG_RETURN_CURRENCY(25);
        case CAD: PG_RETURN_CURRENCY(26);
        case CDF: PG_RETURN_CURRENCY(27);
        case CHF: PG_RETURN_CURRENCY(28);
        case CLP: PG_RETURN_CURRENCY(29);
        case CNY: PG_RETURN_CURRENCY(30);
        case COP: PG_RETURN_CURRENCY(31);
        case CRC: PG_RETURN_CURRENCY(32);
        case CUC: PG_RETURN_CURRENCY(33);
        case CUP: PG_RETURN_CURRENCY(34);
        case CVE: PG_RETURN_CURRENCY(35);
        case CZK: PG_RETURN_CURRENCY(36);
        case DJF: PG_RETURN_CURRENCY(37);
        case DKK: PG_RETURN_CURRENCY(38);
        case DOP: PG_RETURN_CURRENCY(39);
        case DZD: PG_RETURN_CURRENCY(40);
        case EGP: PG_RETURN_CURRENCY(41);
        case ERN: PG_RETURN_CURRENCY(42);
        case ETB: PG_RETURN_CURRENCY(43);
        case EUR: PG_RETURN_CURRENCY(44);
        case FJD: PG_RETURN_CURRENCY(45);
        case FKP: PG_RETURN_CURRENCY(46);
        case GBP: PG_RETURN_CURRENCY(47);
        case GEL: PG_RETURN_CURRENCY(48);
        case GGP: PG_RETURN_CURRENCY(49);
        case GHS: PG_RETURN_CURRENCY(50);
        case GIP: PG_RETURN_CURRENCY(51);
        case GMD: PG_RETURN_CURRENCY(52);
        case GNF: PG_RETURN_CURRENCY(53);
        case GTQ: PG_RETURN_CURRENCY(54);
        case GYD: PG_RETURN_CURRENCY(55);
        case HKD: PG_RETURN_CURRENCY(56);
        case HNL: PG_RETURN_CURRENCY(57);
        case HRK: PG_RETURN_CURRENCY(58);
        case HTG: PG_RETURN_CURRENCY(59);
        case HUF: PG_RETURN_CURRENCY(60);
        case IDR: PG_RETURN_CURRENCY(61);
        case ILS: PG_RETURN_CURRENCY(62);
        case IMP: PG_RETURN_CURRENCY(63);
        case INR: PG_RETURN_CURRENCY(64);
        case IQD: PG_RETURN_CURRENCY(65);
        case IRR: PG_RETURN_CURRENCY(66);
        case ISK: PG_RETURN_CURRENCY(67);
        case JEP: PG_RETURN_CURRENCY(68);
        case JMD: PG_RETURN_CURRENCY(69);
        case JOD: PG_RETURN_CURRENCY(70);
        case JPY: PG_RETURN_CURRENCY(71);
        case KES: PG_RETURN_CURRENCY(72);
        case KGS: PG_RETURN_CURRENCY(73);
        case KHR: PG_RETURN_CURRENCY(74);
        case KMF: PG_RETURN_CURRENCY(75);
        case KPW: PG_RETURN_CURRENCY(76);
        case KRW: PG_RETURN_CURRENCY(77);
        case KWD: PG_RETURN_CURRENCY(78);
        case KYD: PG_RETURN_CURRENCY(79);
        case KZT: PG_RETURN_CURRENCY(80);
        case LAK: PG_RETURN_CURRENCY(81);
        case LBP: PG_RETURN_CURRENCY(82);
        case LKR: PG_RETURN_CURRENCY(83);
        case LRD: PG_RETURN_CURRENCY(84);
        case LSL: PG_RETURN_CURRENCY(85);
        case LTL: PG_RETURN_CURRENCY(86);
        case LYD: PG_RETURN_CURRENCY(87);
        case MAD: PG_RETURN_CURRENCY(88);
        case MDL: PG_RETURN_CURRENCY(89);
        case MGA: PG_RETURN_CURRENCY(90);
        case MKD: PG_RETURN_CURRENCY(91);
        case MMK: PG_RETURN_CURRENCY(92);
        case MNT: PG_RETURN_CURRENCY(93);
        case MOP: PG_RETURN_CURRENCY(94);
        case MRO: PG_RETURN_CURRENCY(95);
        case MUR: PG_RETURN_CURRENCY(96);
        case MVR: PG_RETURN_CURRENCY(97);
        case MWK: PG_RETURN_CURRENCY(98);
        case MXN: PG_RETURN_CURRENCY(99);
        case MYR: PG_RETURN_CURRENCY(100);
        case MZN: PG_RETURN_CURRENCY(101);
        case NAD: PG_RETURN_CURRENCY(102);
        case NGN: PG_RETURN_CURRENCY(103);
        case NIO: PG_RETURN_CURRENCY(104);
        case NOK: PG_RETURN_CURRENCY(105);
        case NPR: PG_RETURN_CURRENCY(106);
        case NZD: PG_RETURN_CURRENCY(107);
        case OMR: PG_RETURN_CURRENCY(108);
        case PAB: PG_RETURN_CURRENCY(109);
        case PEN: PG_RETURN_CURRENCY(110);
        case PGK: PG_RETURN_CURRENCY(111);
        case PHP: PG_RETURN_CURRENCY(112);
        case PKR: PG_RETURN_CURRENCY(113);
        case PLN: PG_RETURN_CURRENCY(114);
        case PYG: PG_RETURN_CURRENCY(115);
        case QAR: PG_RETURN_CURRENCY(116);
        case RON: PG_RETURN_CURRENCY(117);
        case RSD: PG_RETURN_CURRENCY(118);
        case RUB: PG_RETURN_CURRENCY(119);
        case RWF: PG_RETURN_CURRENCY(120);
        case SAR: PG_RETURN_CURRENCY(121);
        case SBD: PG_RETURN_CURRENCY(122);
        case SCR: PG_RETURN_CURRENCY(123);
        case SDG: PG_RETURN_CURRENCY(124);
        case SEK: PG_RETURN_CURRENCY(125);
        case SGD: PG_RETURN_CURRENCY(126);
        case SHP: PG_RETURN_CURRENCY(127);
        case SLL: PG_RETURN_CURRENCY(128);
        case SOS: PG_RETURN_CURRENCY(129);
        case SPL: PG_RETURN_CURRENCY(130);
        case SRD: PG_RETURN_CURRENCY(131);
        case STD: PG_RETURN_CURRENCY(132);
        case SVC: PG_RETURN_CURRENCY(133);
        case SYP: PG_RETURN_CURRENCY(134);
        case SZL: PG_RETURN_CURRENCY(135);
        case THB: PG_RETURN_CURRENCY(136);
        case TJS: PG_RETURN_CURRENCY(137);
        case TMT: PG_RETURN_CURRENCY(138);
        case TND: PG_RETURN_CURRENCY(139);
        case TOP: PG_RETURN_CURRENCY(140);
        case TRY: PG_RETURN_CURRENCY(141);
        case TTD: PG_RETURN_CURRENCY(142);
        case TVD: PG_RETURN_CURRENCY(143);
        case TWD: PG_RETURN_CURRENCY(144);
        case TZS: PG_RETURN_CURRENCY(145);
        case UAH: PG_RETURN_CURRENCY(146);
        case UGX: PG_RETURN_CURRENCY(147);
        case USD: PG_RETURN_CURRENCY(148);
        case UYU: PG_RETURN_CURRENCY(149);
        case UZS: PG_RETURN_CURRENCY(150);
        case VEF: PG_RETURN_CURRENCY(151);
        case VND: PG_RETURN_CURRENCY(152);
        case VUV: PG_RETURN_CURRENCY(153);
        case WST: PG_RETURN_CURRENCY(154);
        case XAF: PG_RETURN_CURRENCY(155);
        case XCD: PG_RETURN_CURRENCY(156);
        case XDR: PG_RETURN_CURRENCY(157);
        case XOF: PG_RETURN_CURRENCY(158);
        case XPF: PG_RETURN_CURRENCY(159);
        case YER: PG_RETURN_CURRENCY(160);
        case ZAR: PG_RETURN_CURRENCY(161);
        case ZMW: PG_RETURN_CURRENCY(162);
        case ZWD: PG_RETURN_CURRENCY(163);
        case BYN: PG_RETURN_CURRENCY(164);
        default: elog(ERROR, "unknown currency type: %s", str);
    }
}

Datum
currency_out(PG_FUNCTION_ARGS)
{
    currency curr = PG_GETARG_CHAR(0);
    char *out = palloc(4);
    uint32 key = 0;
    switch (curr)
    {
        case 1:
            key = AED;
            break;
        case 2:
            key = AFN;
            break;
        case 3:
            key = ALL;
            break;
        case 4:
            key = AMD;
            break;
        case 5:
            key = ANG;
            break;
        case 6:
            key = AOA;
            break;
        case 7:
            key = ARS;
            break;
        case 8:
            key = AUD;
            break;
        case 9:
            key = AWG;
            break;
        case 10:
            key = AZN;
            break;
        case 11:
            key = BAM;
            break;
        case 12:
            key = BBD;
            break;
        case 13:
            key = BDT;
            break;
        case 14:
            key = BGN;
            break;
        case 15:
            key = BHD;
            break;
        case 16:
            key = BIF;
            break;
        case 17:
            key = BMD;
            break;
        case 18:
            key = BND;
            break;
        case 19:
            key = BOB;
            break;
        case 20:
            key = BRL;
            break;
        case 21:
            key = BSD;
            break;
        case 22:
            key = BTN;
            break;
        case 23:
            key = BWP;
            break;
        case 24:
            key = BYR;
            break;
        case 25:
            key = BZD;
            break;
        case 26:
            key = CAD;
            break;
        case 27:
            key = CDF;
            break;
        case 28:
            key = CHF;
            break;
        case 29:
            key = CLP;
            break;
        case 30:
            key = CNY;
            break;
        case 31:
            key = COP;
            break;
        case 32:
            key = CRC;
            break;
        case 33:
            key = CUC;
            break;
        case 34:
            key = CUP;
            break;
        case 35:
            key = CVE;
            break;
        case 36:
            key = CZK;
            break;
        case 37:
            key = DJF;
            break;
        case 38:
            key = DKK;
            break;
        case 39:
            key = DOP;
            break;
        case 40:
            key = DZD;
            break;
        case 41:
            key = EGP;
            break;
        case 42:
            key = ERN;
            break;
        case 43:
            key = ETB;
            break;
        case 44:
            key = EUR;
            break;
        case 45:
            key = FJD;
            break;
        case 46:
            key = FKP;
            break;
        case 47:
            key = GBP;
            break;
        case 48:
            key = GEL;
            break;
        case 49:
            key = GGP;
            break;
        case 50:
            key = GHS;
            break;
        case 51:
            key = GIP;
            break;
        case 52:
            key = GMD;
            break;
        case 53:
            key = GNF;
            break;
        case 54:
            key = GTQ;
            break;
        case 55:
            key = GYD;
            break;
        case 56:
            key = HKD;
            break;
        case 57:
            key = HNL;
            break;
        case 58:
            key = HRK;
            break;
        case 59:
            key = HTG;
            break;
        case 60:
            key = HUF;
            break;
        case 61:
            key = IDR;
            break;
        case 62:
            key = ILS;
            break;
        case 63:
            key = IMP;
            break;
        case 64:
            key = INR;
            break;
        case 65:
            key = IQD;
            break;
        case 66:
            key = IRR;
            break;
        case 67:
            key = ISK;
            break;
        case 68:
            key = JEP;
            break;
        case 69:
            key = JMD;
            break;
        case 70:
            key = JOD;
            break;
        case 71:
            key = JPY;
            break;
        case 72:
            key = KES;
            break;
        case 73:
            key = KGS;
            break;
        case 74:
            key = KHR;
            break;
        case 75:
            key = KMF;
            break;
        case 76:
            key = KPW;
            break;
        case 77:
            key = KRW;
            break;
        case 78:
            key = KWD;
            break;
        case 79:
            key = KYD;
            break;
        case 80:
            key = KZT;
            break;
        case 81:
            key = LAK;
            break;
        case 82:
            key = LBP;
            break;
        case 83:
            key = LKR;
            break;
        case 84:
            key = LRD;
            break;
        case 85:
            key = LSL;
            break;
        case 86:
            key = LTL;
            break;
        case 87:
            key = LYD;
            break;
        case 88:
            key = MAD;
            break;
        case 89:
            key = MDL;
            break;
        case 90:
            key = MGA;
            break;
        case 91:
            key = MKD;
            break;
        case 92:
            key = MMK;
            break;
        case 93:
            key = MNT;
            break;
        case 94:
            key = MOP;
            break;
        case 95:
            key = MRO;
            break;
        case 96:
            key = MUR;
            break;
        case 97:
            key = MVR;
            break;
        case 98:
            key = MWK;
            break;
        case 99:
            key = MXN;
            break;
        case 100:
            key = MYR;
            break;
        case 101:
            key = MZN;
            break;
        case 102:
            key = NAD;
            break;
        case 103:
            key = NGN;
            break;
        case 104:
            key = NIO;
            break;
        case 105:
            key = NOK;
            break;
        case 106:
            key = NPR;
            break;
        case 107:
            key = NZD;
            break;
        case 108:
            key = OMR;
            break;
        case 109:
            key = PAB;
            break;
        case 110:
            key = PEN;
            break;
        case 111:
            key = PGK;
            break;
        case 112:
            key = PHP;
            break;
        case 113:
            key = PKR;
            break;
        case 114:
            key = PLN;
            break;
        case 115:
            key = PYG;
            break;
        case 116:
            key = QAR;
            break;
        case 117:
            key = RON;
            break;
        case 118:
            key = RSD;
            break;
        case 119:
            key = RUB;
            break;
        case 120:
            key = RWF;
            break;
        case 121:
            key = SAR;
            break;
        case 122:
            key = SBD;
            break;
        case 123:
            key = SCR;
            break;
        case 124:
            key = SDG;
            break;
        case 125:
            key = SEK;
            break;
        case 126:
            key = SGD;
            break;
        case 127:
            key = SHP;
            break;
        case 128:
            key = SLL;
            break;
        case 129:
            key = SOS;
            break;
        case 130:
            key = SPL;
            break;
        case 131:
            key = SRD;
            break;
        case 132:
            key = STD;
            break;
        case 133:
            key = SVC;
            break;
        case 134:
            key = SYP;
            break;
        case 135:
            key = SZL;
            break;
        case 136:
            key = THB;
            break;
        case 137:
            key = TJS;
            break;
        case 138:
            key = TMT;
            break;
        case 139:
            key = TND;
            break;
        case 140:
            key = TOP;
            break;
        case 141:
            key = TRY;
            break;
        case 142:
            key = TTD;
            break;
        case 143:
            key = TVD;
            break;
        case 144:
            key = TWD;
            break;
        case 145:
            key = TZS;
            break;
        case 146:
            key = UAH;
            break;
        case 147:
            key = UGX;
            break;
        case 148:
            key = USD;
            break;
        case 149:
            key = UYU;
            break;
        case 150:
            key = UZS;
            break;
        case 151:
            key = VEF;
            break;
        case 152:
            key = VND;
            break;
        case 153:
            key = VUV;
            break;
        case 154:
            key = WST;
            break;
        case 155:
            key = XAF;
            break;
        case 156:
            key = XCD;
            break;
        case 157:
            key = XDR;
            break;
        case 158:
            key = XOF;
            break;
        case 159:
            key = XPF;
            break;
        case 160:
            key = YER;
            break;
        case 161:
            key = ZAR;
            break;
        case 162:
            key = ZMW;
            break;
        case 163:
            key = ZWD;
            break;
        case 164:
            key = BYN;
            break;
        default:
            elog(ERROR, "internal currency representation unknown: %u", key);
    }
    snprintf(
            out,
            4,
            "%c%c%c",
            (key & 0xFF0000) >> 16,
            (key & 0xFF00) >> 8,
            (key & 0xFF)
    );
    PG_RETURN_POINTER(out);
}

Datum
currency_recv(PG_FUNCTION_ARGS)
{
    StringInfo buf = (StringInfo) PG_GETARG_POINTER(0);
    currency result = pq_getmsgbyte(buf);
    PG_RETURN_CURRENCY(result);
}

Datum
currency_send(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    StringInfoData buf;

    pq_begintypsend(&buf);
    pq_sendbyte(&buf, a);
    PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}

Datum
currency_lt(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) < 0);
}

Datum
currency_le(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) <= 0);
}

Datum
currency_eq(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) == 0);
}

Datum
currency_neq(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) != 0);
}

Datum
currency_ge(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) >= 0);
}

Datum
currency_gt(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_BOOL(currency_cmp_internal(a, b) > 0);
}

Datum
currency_cmp(PG_FUNCTION_ARGS)
{
    currency a = PG_GETARG_CURRENCY(0);
    currency b = PG_GETARG_CURRENCY(1);
    PG_RETURN_INT32(currency_cmp_internal(a, b));
}

Datum
hash_currency(PG_FUNCTION_ARGS)
{
        return hash_uint32((int32) PG_GETARG_CHAR(0));
}
