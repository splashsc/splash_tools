char *__fastcall httpd_find_type(const char *a1)
{
  char *v1; // $v0
  int v2; // $v0
  char *result; // $v0

  v1 = strrchr(a1, 46);
  if ( !v1 )
    return httpd_file_xtypes[0];
  switch ( v1[1] )
  {
    case 'c':
      return off_6676E0[0];
    case 'e':
    case 'o':
    case 'r':
      return off_667704[0];
    case 'g':
      return off_6676E4[0];
    case 'i':
      return off_6676F0[0];
    case 'j':
      if ( v1[2] == 112 )
        result = off_6676E8[0];
      else
        result = off_6676F4[0];
      return result;
    case 'p':
      return off_6676EC[0];
    case 's':
      v2 = v1[2];
      if ( v2 == 119 )
      {
        result = off_667708[0];
      }
      else
      {
        if ( v2 != 118 )
          return httpd_file_xtypes[0];
        result = off_66770C;
      }
      break;
    case 't':
      if ( v1[2] == 97 )
        result = off_667700[0];
      else
        result = off_6676F8[0];
      return result;
    case 'x':
      return off_6676DC[0];
    case 'z':
      return off_6676FC[0];
    default:
      return httpd_file_xtypes[0];
  }
  return result;
}
// 6676D8: using guessed type char *httpd_file_xtypes[14];
// 6676DC: using guessed type char *off_6676DC[13];
// 6676E0: using guessed type char *off_6676E0[12];
// 6676E4: using guessed type char *off_6676E4[11];
// 6676E8: using guessed type char *off_6676E8[10];
// 6676EC: using guessed type char *off_6676EC[9];
// 6676F0: using guessed type char *off_6676F0[8];
// 6676F4: using guessed type char *off_6676F4[7];
// 6676F8: using guessed type char *off_6676F8[6];
// 6676FC: using guessed type char *off_6676FC[5];
// 667700: using guessed type char *off_667700[4];
// 667704: using guessed type char *off_667704[3];
// 667708: using guessed type char *off_667708[2];
// 66770C: using guessed type char *off_66770C;

