int __fastcall get_rule_num_limit(int a1)
{
  int result; // $v0

  switch ( a1 )
  {
    case 0:
      result = 32;
      break;
    case 1:
      result = sq_file_get_max_wan_no4g();
      break;
    case 2:
    case 3:
    case 5:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 24:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
      result = 1024;
      break;
    case 8:
    case 37:
    case 41:
      result = 64;
      break;
    case 25:
      result = 1000;
      break;
    case 26:
    case 35:
    case 38:
    case 39:
      result = 512;
      break;
    case 36:
    case 40:
      result = 128;
      break;
    default:
      result = 256;
      break;
  }
  return result;
}
// 6A86E8: using guessed type int sq_file_get_max_wan_no4g(void);

