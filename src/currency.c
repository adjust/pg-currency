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

_Static_assert (LAST == sizeof(sort_map) / sizeof(sort_map[0]) + 1, "sort map size and Currency size should be equal");

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
        case AED: PG_RETURN_CURRENCY(AED_INTERNAL);
        case AFN: PG_RETURN_CURRENCY(AFN_INTERNAL);
        case ALL: PG_RETURN_CURRENCY(ALL_INTERNAL);
        case AMD: PG_RETURN_CURRENCY(AMD_INTERNAL);
        case ANG: PG_RETURN_CURRENCY(ANG_INTERNAL);
        case AOA: PG_RETURN_CURRENCY(AOA_INTERNAL);
        case ARS: PG_RETURN_CURRENCY(ARS_INTERNAL);
        case AUD: PG_RETURN_CURRENCY(AUD_INTERNAL);
        case AWG: PG_RETURN_CURRENCY(AWG_INTERNAL);
        case AZN: PG_RETURN_CURRENCY(AZN_INTERNAL);
        case BAM: PG_RETURN_CURRENCY(BAM_INTERNAL);
        case BBD: PG_RETURN_CURRENCY(BBD_INTERNAL);
        case BDT: PG_RETURN_CURRENCY(BDT_INTERNAL);
        case BGN: PG_RETURN_CURRENCY(BGN_INTERNAL);
        case BHD: PG_RETURN_CURRENCY(BHD_INTERNAL);
        case BIF: PG_RETURN_CURRENCY(BIF_INTERNAL);
        case BMD: PG_RETURN_CURRENCY(BMD_INTERNAL);
        case BND: PG_RETURN_CURRENCY(BND_INTERNAL);
        case BOB: PG_RETURN_CURRENCY(BOB_INTERNAL);
        case BRL: PG_RETURN_CURRENCY(BRL_INTERNAL);
        case BSD: PG_RETURN_CURRENCY(BSD_INTERNAL);
        case BTN: PG_RETURN_CURRENCY(BTN_INTERNAL);
        case BWP: PG_RETURN_CURRENCY(BWP_INTERNAL);
        case BYN: PG_RETURN_CURRENCY(BYN_INTERNAL);
        case BYR: PG_RETURN_CURRENCY(BYR_INTERNAL);
        case BZD: PG_RETURN_CURRENCY(BZD_INTERNAL);
        case CAD: PG_RETURN_CURRENCY(CAD_INTERNAL);
        case CDF: PG_RETURN_CURRENCY(CDF_INTERNAL);
        case CHF: PG_RETURN_CURRENCY(CHF_INTERNAL);
        case CLP: PG_RETURN_CURRENCY(CLP_INTERNAL);
        case CNY: PG_RETURN_CURRENCY(CNY_INTERNAL);
        case COP: PG_RETURN_CURRENCY(COP_INTERNAL);
        case CRC: PG_RETURN_CURRENCY(CRC_INTERNAL);
        case CUC: PG_RETURN_CURRENCY(CUC_INTERNAL);
        case CUP: PG_RETURN_CURRENCY(CUP_INTERNAL);
        case CVE: PG_RETURN_CURRENCY(CVE_INTERNAL);
        case CZK: PG_RETURN_CURRENCY(CZK_INTERNAL);
        case DJF: PG_RETURN_CURRENCY(DJF_INTERNAL);
        case DKK: PG_RETURN_CURRENCY(DKK_INTERNAL);
        case DOP: PG_RETURN_CURRENCY(DOP_INTERNAL);
        case DZD: PG_RETURN_CURRENCY(DZD_INTERNAL);
        case EGP: PG_RETURN_CURRENCY(EGP_INTERNAL);
        case ERN: PG_RETURN_CURRENCY(ERN_INTERNAL);
        case ETB: PG_RETURN_CURRENCY(ETB_INTERNAL);
        case EUR: PG_RETURN_CURRENCY(EUR_INTERNAL);
        case FJD: PG_RETURN_CURRENCY(FJD_INTERNAL);
        case FKP: PG_RETURN_CURRENCY(FKP_INTERNAL);
        case GBP: PG_RETURN_CURRENCY(GBP_INTERNAL);
        case GEL: PG_RETURN_CURRENCY(GEL_INTERNAL);
        case GGP: PG_RETURN_CURRENCY(GGP_INTERNAL);
        case GHS: PG_RETURN_CURRENCY(GHS_INTERNAL);
        case GIP: PG_RETURN_CURRENCY(GIP_INTERNAL);
        case GMD: PG_RETURN_CURRENCY(GMD_INTERNAL);
        case GNF: PG_RETURN_CURRENCY(GNF_INTERNAL);
        case GTQ: PG_RETURN_CURRENCY(GTQ_INTERNAL);
        case GYD: PG_RETURN_CURRENCY(GYD_INTERNAL);
        case HKD: PG_RETURN_CURRENCY(HKD_INTERNAL);
        case HNL: PG_RETURN_CURRENCY(HNL_INTERNAL);
        case HRK: PG_RETURN_CURRENCY(HRK_INTERNAL);
        case HTG: PG_RETURN_CURRENCY(HTG_INTERNAL);
        case HUF: PG_RETURN_CURRENCY(HUF_INTERNAL);
        case IDR: PG_RETURN_CURRENCY(IDR_INTERNAL);
        case ILS: PG_RETURN_CURRENCY(ILS_INTERNAL);
        case IMP: PG_RETURN_CURRENCY(IMP_INTERNAL);
        case INR: PG_RETURN_CURRENCY(INR_INTERNAL);
        case IQD: PG_RETURN_CURRENCY(IQD_INTERNAL);
        case IRR: PG_RETURN_CURRENCY(IRR_INTERNAL);
        case ISK: PG_RETURN_CURRENCY(ISK_INTERNAL);
        case JEP: PG_RETURN_CURRENCY(JEP_INTERNAL);
        case JMD: PG_RETURN_CURRENCY(JMD_INTERNAL);
        case JOD: PG_RETURN_CURRENCY(JOD_INTERNAL);
        case JPY: PG_RETURN_CURRENCY(JPY_INTERNAL);
        case KES: PG_RETURN_CURRENCY(KES_INTERNAL);
        case KGS: PG_RETURN_CURRENCY(KGS_INTERNAL);
        case KHR: PG_RETURN_CURRENCY(KHR_INTERNAL);
        case KMF: PG_RETURN_CURRENCY(KMF_INTERNAL);
        case KPW: PG_RETURN_CURRENCY(KPW_INTERNAL);
        case KRW: PG_RETURN_CURRENCY(KRW_INTERNAL);
        case KWD: PG_RETURN_CURRENCY(KWD_INTERNAL);
        case KYD: PG_RETURN_CURRENCY(KYD_INTERNAL);
        case KZT: PG_RETURN_CURRENCY(KZT_INTERNAL);
        case LAK: PG_RETURN_CURRENCY(LAK_INTERNAL);
        case LBP: PG_RETURN_CURRENCY(LBP_INTERNAL);
        case LKR: PG_RETURN_CURRENCY(LKR_INTERNAL);
        case LRD: PG_RETURN_CURRENCY(LRD_INTERNAL);
        case LSL: PG_RETURN_CURRENCY(LSL_INTERNAL);
        case LTL: PG_RETURN_CURRENCY(LTL_INTERNAL);
        case LYD: PG_RETURN_CURRENCY(LYD_INTERNAL);
        case MAD: PG_RETURN_CURRENCY(MAD_INTERNAL);
        case MDL: PG_RETURN_CURRENCY(MDL_INTERNAL);
        case MGA: PG_RETURN_CURRENCY(MGA_INTERNAL);
        case MKD: PG_RETURN_CURRENCY(MKD_INTERNAL);
        case MMK: PG_RETURN_CURRENCY(MMK_INTERNAL);
        case MNT: PG_RETURN_CURRENCY(MNT_INTERNAL);
        case MOP: PG_RETURN_CURRENCY(MOP_INTERNAL);
        case MRO: PG_RETURN_CURRENCY(MRO_INTERNAL);
        case MUR: PG_RETURN_CURRENCY(MUR_INTERNAL);
        case MVR: PG_RETURN_CURRENCY(MVR_INTERNAL);
        case MWK: PG_RETURN_CURRENCY(MWK_INTERNAL);
        case MXN: PG_RETURN_CURRENCY(MXN_INTERNAL);
        case MYR: PG_RETURN_CURRENCY(MYR_INTERNAL);
        case MZN: PG_RETURN_CURRENCY(MZN_INTERNAL);
        case NAD: PG_RETURN_CURRENCY(NAD_INTERNAL);
        case NGN: PG_RETURN_CURRENCY(NGN_INTERNAL);
        case NIO: PG_RETURN_CURRENCY(NIO_INTERNAL);
        case NOK: PG_RETURN_CURRENCY(NOK_INTERNAL);
        case NPR: PG_RETURN_CURRENCY(NPR_INTERNAL);
        case NZD: PG_RETURN_CURRENCY(NZD_INTERNAL);
        case OMR: PG_RETURN_CURRENCY(OMR_INTERNAL);
        case PAB: PG_RETURN_CURRENCY(PAB_INTERNAL);
        case PEN: PG_RETURN_CURRENCY(PEN_INTERNAL);
        case PGK: PG_RETURN_CURRENCY(PGK_INTERNAL);
        case PHP: PG_RETURN_CURRENCY(PHP_INTERNAL);
        case PKR: PG_RETURN_CURRENCY(PKR_INTERNAL);
        case PLN: PG_RETURN_CURRENCY(PLN_INTERNAL);
        case PYG: PG_RETURN_CURRENCY(PYG_INTERNAL);
        case QAR: PG_RETURN_CURRENCY(QAR_INTERNAL);
        case RON: PG_RETURN_CURRENCY(RON_INTERNAL);
        case RSD: PG_RETURN_CURRENCY(RSD_INTERNAL);
        case RUB: PG_RETURN_CURRENCY(RUB_INTERNAL);
        case RWF: PG_RETURN_CURRENCY(RWF_INTERNAL);
        case SAR: PG_RETURN_CURRENCY(SAR_INTERNAL);
        case SBD: PG_RETURN_CURRENCY(SBD_INTERNAL);
        case SCR: PG_RETURN_CURRENCY(SCR_INTERNAL);
        case SDG: PG_RETURN_CURRENCY(SDG_INTERNAL);
        case SEK: PG_RETURN_CURRENCY(SEK_INTERNAL);
        case SGD: PG_RETURN_CURRENCY(SGD_INTERNAL);
        case SHP: PG_RETURN_CURRENCY(SHP_INTERNAL);
        case SLL: PG_RETURN_CURRENCY(SLL_INTERNAL);
        case SOS: PG_RETURN_CURRENCY(SOS_INTERNAL);
        case SPL: PG_RETURN_CURRENCY(SPL_INTERNAL);
        case SRD: PG_RETURN_CURRENCY(SRD_INTERNAL);
        case STD: PG_RETURN_CURRENCY(STD_INTERNAL);
        case SVC: PG_RETURN_CURRENCY(SVC_INTERNAL);
        case SYP: PG_RETURN_CURRENCY(SYP_INTERNAL);
        case SZL: PG_RETURN_CURRENCY(SZL_INTERNAL);
        case THB: PG_RETURN_CURRENCY(THB_INTERNAL);
        case TJS: PG_RETURN_CURRENCY(TJS_INTERNAL);
        case TMT: PG_RETURN_CURRENCY(TMT_INTERNAL);
        case TND: PG_RETURN_CURRENCY(TND_INTERNAL);
        case TOP: PG_RETURN_CURRENCY(TOP_INTERNAL);
        case TRY: PG_RETURN_CURRENCY(TRY_INTERNAL);
        case TTD: PG_RETURN_CURRENCY(TTD_INTERNAL);
        case TVD: PG_RETURN_CURRENCY(TVD_INTERNAL);
        case TWD: PG_RETURN_CURRENCY(TWD_INTERNAL);
        case TZS: PG_RETURN_CURRENCY(TZS_INTERNAL);
        case UAH: PG_RETURN_CURRENCY(UAH_INTERNAL);
        case UGX: PG_RETURN_CURRENCY(UGX_INTERNAL);
        case USD: PG_RETURN_CURRENCY(USD_INTERNAL);
        case UYU: PG_RETURN_CURRENCY(UYU_INTERNAL);
        case UZS: PG_RETURN_CURRENCY(UZS_INTERNAL);
        case VEF: PG_RETURN_CURRENCY(VEF_INTERNAL);
        case VND: PG_RETURN_CURRENCY(VND_INTERNAL);
        case VUV: PG_RETURN_CURRENCY(VUV_INTERNAL);
        case WST: PG_RETURN_CURRENCY(WST_INTERNAL);
        case XAF: PG_RETURN_CURRENCY(XAF_INTERNAL);
        case XCD: PG_RETURN_CURRENCY(XCD_INTERNAL);
        case XDR: PG_RETURN_CURRENCY(XDR_INTERNAL);
        case XOF: PG_RETURN_CURRENCY(XOF_INTERNAL);
        case XPF: PG_RETURN_CURRENCY(XPF_INTERNAL);
        case YER: PG_RETURN_CURRENCY(YER_INTERNAL);
        case ZAR: PG_RETURN_CURRENCY(ZAR_INTERNAL);
        case ZMW: PG_RETURN_CURRENCY(ZMW_INTERNAL);
        case ZWD: PG_RETURN_CURRENCY(ZWD_INTERNAL);
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
        case AED_INTERNAL:
            key = AED;
            break;
        case AFN_INTERNAL:
            key = AFN;
            break;
        case ALL_INTERNAL:
            key = ALL;
            break;
        case AMD_INTERNAL:
            key = AMD;
            break;
        case ANG_INTERNAL:
            key = ANG;
            break;
        case AOA_INTERNAL:
            key = AOA;
            break;
        case ARS_INTERNAL:
            key = ARS;
            break;
        case AUD_INTERNAL:
            key = AUD;
            break;
        case AWG_INTERNAL:
            key = AWG;
            break;
        case AZN_INTERNAL:
            key = AZN;
            break;
        case BAM_INTERNAL:
            key = BAM;
            break;
        case BBD_INTERNAL:
            key = BBD;
            break;
        case BDT_INTERNAL:
            key = BDT;
            break;
        case BGN_INTERNAL:
            key = BGN;
            break;
        case BHD_INTERNAL:
            key = BHD;
            break;
        case BIF_INTERNAL:
            key = BIF;
            break;
        case BMD_INTERNAL:
            key = BMD;
            break;
        case BND_INTERNAL:
            key = BND;
            break;
        case BOB_INTERNAL:
            key = BOB;
            break;
        case BRL_INTERNAL:
            key = BRL;
            break;
        case BSD_INTERNAL:
            key = BSD;
            break;
        case BTN_INTERNAL:
            key = BTN;
            break;
        case BWP_INTERNAL:
            key = BWP;
            break;
        case BYN_INTERNAL:
            key = BYN;
            break;
        case BYR_INTERNAL:
            key = BYR;
            break;
        case BZD_INTERNAL:
            key = BZD;
            break;
        case CAD_INTERNAL:
            key = CAD;
            break;
        case CDF_INTERNAL:
            key = CDF;
            break;
        case CHF_INTERNAL:
            key = CHF;
            break;
        case CLP_INTERNAL:
            key = CLP;
            break;
        case CNY_INTERNAL:
            key = CNY;
            break;
        case COP_INTERNAL:
            key = COP;
            break;
        case CRC_INTERNAL:
            key = CRC;
            break;
        case CUC_INTERNAL:
            key = CUC;
            break;
        case CUP_INTERNAL:
            key = CUP;
            break;
        case CVE_INTERNAL:
            key = CVE;
            break;
        case CZK_INTERNAL:
            key = CZK;
            break;
        case DJF_INTERNAL:
            key = DJF;
            break;
        case DKK_INTERNAL:
            key = DKK;
            break;
        case DOP_INTERNAL:
            key = DOP;
            break;
        case DZD_INTERNAL:
            key = DZD;
            break;
        case EGP_INTERNAL:
            key = EGP;
            break;
        case ERN_INTERNAL:
            key = ERN;
            break;
        case ETB_INTERNAL:
            key = ETB;
            break;
        case EUR_INTERNAL:
            key = EUR;
            break;
        case FJD_INTERNAL:
            key = FJD;
            break;
        case FKP_INTERNAL:
            key = FKP;
            break;
        case GBP_INTERNAL:
            key = GBP;
            break;
        case GEL_INTERNAL:
            key = GEL;
            break;
        case GGP_INTERNAL:
            key = GGP;
            break;
        case GHS_INTERNAL:
            key = GHS;
            break;
        case GIP_INTERNAL:
            key = GIP;
            break;
        case GMD_INTERNAL:
            key = GMD;
            break;
        case GNF_INTERNAL:
            key = GNF;
            break;
        case GTQ_INTERNAL:
            key = GTQ;
            break;
        case GYD_INTERNAL:
            key = GYD;
            break;
        case HKD_INTERNAL:
            key = HKD;
            break;
        case HNL_INTERNAL:
            key = HNL;
            break;
        case HRK_INTERNAL:
            key = HRK;
            break;
        case HTG_INTERNAL:
            key = HTG;
            break;
        case HUF_INTERNAL:
            key = HUF;
            break;
        case IDR_INTERNAL:
            key = IDR;
            break;
        case ILS_INTERNAL:
            key = ILS;
            break;
        case IMP_INTERNAL:
            key = IMP;
            break;
        case INR_INTERNAL:
            key = INR;
            break;
        case IQD_INTERNAL:
            key = IQD;
            break;
        case IRR_INTERNAL:
            key = IRR;
            break;
        case ISK_INTERNAL:
            key = ISK;
            break;
        case JEP_INTERNAL:
            key = JEP;
            break;
        case JMD_INTERNAL:
            key = JMD;
            break;
        case JOD_INTERNAL:
            key = JOD;
            break;
        case JPY_INTERNAL:
            key = JPY;
            break;
        case KES_INTERNAL:
            key = KES;
            break;
        case KGS_INTERNAL:
            key = KGS;
            break;
        case KHR_INTERNAL:
            key = KHR;
            break;
        case KMF_INTERNAL:
            key = KMF;
            break;
        case KPW_INTERNAL:
            key = KPW;
            break;
        case KRW_INTERNAL:
            key = KRW;
            break;
        case KWD_INTERNAL:
            key = KWD;
            break;
        case KYD_INTERNAL:
            key = KYD;
            break;
        case KZT_INTERNAL:
            key = KZT;
            break;
        case LAK_INTERNAL:
            key = LAK;
            break;
        case LBP_INTERNAL:
            key = LBP;
            break;
        case LKR_INTERNAL:
            key = LKR;
            break;
        case LRD_INTERNAL:
            key = LRD;
            break;
        case LSL_INTERNAL:
            key = LSL;
            break;
        case LTL_INTERNAL:
            key = LTL;
            break;
        case LYD_INTERNAL:
            key = LYD;
            break;
        case MAD_INTERNAL:
            key = MAD;
            break;
        case MDL_INTERNAL:
            key = MDL;
            break;
        case MGA_INTERNAL:
            key = MGA;
            break;
        case MKD_INTERNAL:
            key = MKD;
            break;
        case MMK_INTERNAL:
            key = MMK;
            break;
        case MNT_INTERNAL:
            key = MNT;
            break;
        case MOP_INTERNAL:
            key = MOP;
            break;
        case MRO_INTERNAL:
            key = MRO;
            break;
        case MUR_INTERNAL:
            key = MUR;
            break;
        case MVR_INTERNAL:
            key = MVR;
            break;
        case MWK_INTERNAL:
            key = MWK;
            break;
        case MXN_INTERNAL:
            key = MXN;
            break;
        case MYR_INTERNAL:
            key = MYR;
            break;
        case MZN_INTERNAL:
            key = MZN;
            break;
        case NAD_INTERNAL:
            key = NAD;
            break;
        case NGN_INTERNAL:
            key = NGN;
            break;
        case NIO_INTERNAL:
            key = NIO;
            break;
        case NOK_INTERNAL:
            key = NOK;
            break;
        case NPR_INTERNAL:
            key = NPR;
            break;
        case NZD_INTERNAL:
            key = NZD;
            break;
        case OMR_INTERNAL:
            key = OMR;
            break;
        case PAB_INTERNAL:
            key = PAB;
            break;
        case PEN_INTERNAL:
            key = PEN;
            break;
        case PGK_INTERNAL:
            key = PGK;
            break;
        case PHP_INTERNAL:
            key = PHP;
            break;
        case PKR_INTERNAL:
            key = PKR;
            break;
        case PLN_INTERNAL:
            key = PLN;
            break;
        case PYG_INTERNAL:
            key = PYG;
            break;
        case QAR_INTERNAL:
            key = QAR;
            break;
        case RON_INTERNAL:
            key = RON;
            break;
        case RSD_INTERNAL:
            key = RSD;
            break;
        case RUB_INTERNAL:
            key = RUB;
            break;
        case RWF_INTERNAL:
            key = RWF;
            break;
        case SAR_INTERNAL:
            key = SAR;
            break;
        case SBD_INTERNAL:
            key = SBD;
            break;
        case SCR_INTERNAL:
            key = SCR;
            break;
        case SDG_INTERNAL:
            key = SDG;
            break;
        case SEK_INTERNAL:
            key = SEK;
            break;
        case SGD_INTERNAL:
            key = SGD;
            break;
        case SHP_INTERNAL:
            key = SHP;
            break;
        case SLL_INTERNAL:
            key = SLL;
            break;
        case SOS_INTERNAL:
            key = SOS;
            break;
        case SPL_INTERNAL:
            key = SPL;
            break;
        case SRD_INTERNAL:
            key = SRD;
            break;
        case STD_INTERNAL:
            key = STD;
            break;
        case SVC_INTERNAL:
            key = SVC;
            break;
        case SYP_INTERNAL:
            key = SYP;
            break;
        case SZL_INTERNAL:
            key = SZL;
            break;
        case THB_INTERNAL:
            key = THB;
            break;
        case TJS_INTERNAL:
            key = TJS;
            break;
        case TMT_INTERNAL:
            key = TMT;
            break;
        case TND_INTERNAL:
            key = TND;
            break;
        case TOP_INTERNAL:
            key = TOP;
            break;
        case TRY_INTERNAL:
            key = TRY;
            break;
        case TTD_INTERNAL:
            key = TTD;
            break;
        case TVD_INTERNAL:
            key = TVD;
            break;
        case TWD_INTERNAL:
            key = TWD;
            break;
        case TZS_INTERNAL:
            key = TZS;
            break;
        case UAH_INTERNAL:
            key = UAH;
            break;
        case UGX_INTERNAL:
            key = UGX;
            break;
        case USD_INTERNAL:
            key = USD;
            break;
        case UYU_INTERNAL:
            key = UYU;
            break;
        case UZS_INTERNAL:
            key = UZS;
            break;
        case VEF_INTERNAL:
            key = VEF;
            break;
        case VND_INTERNAL:
            key = VND;
            break;
        case VUV_INTERNAL:
            key = VUV;
            break;
        case WST_INTERNAL:
            key = WST;
            break;
        case XAF_INTERNAL:
            key = XAF;
            break;
        case XCD_INTERNAL:
            key = XCD;
            break;
        case XDR_INTERNAL:
            key = XDR;
            break;
        case XOF_INTERNAL:
            key = XOF;
            break;
        case XPF_INTERNAL:
            key = XPF;
            break;
        case YER_INTERNAL:
            key = YER;
            break;
        case ZAR_INTERNAL:
            key = ZAR;
            break;
        case ZMW_INTERNAL:
            key = ZMW;
            break;
        case ZWD_INTERNAL:
            key = ZWD;
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

Datum
supported_currencies(PG_FUNCTION_ARGS)
{
    FuncCallContext *funcctx;

    /* stuff done only on the first call of the function */
    if (SRF_IS_FIRSTCALL())
    {
        /* create a function context for cross-call persistence */
        funcctx = SRF_FIRSTCALL_INIT();
    }

    /* stuff done on every call of the function */
    funcctx = SRF_PERCALL_SETUP();

    if (funcctx->call_cntr < LAST - 1)
    {
        Datum currency = CurrencyGetDatum(funcctx->call_cntr + 1);

        /* do when there is more left to send */
        SRF_RETURN_NEXT(funcctx, currency);
    }
    else
    {
        /* do when there is no more left */
        SRF_RETURN_DONE(funcctx);
    }
}
