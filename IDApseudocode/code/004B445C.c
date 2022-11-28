bool __fastcall f_exists64(const char *a1)
{
  bool v1; // dc
  _BOOL4 result; // $v0
  struct stat v3; // [sp+18h] [-A4h] BYREF

  v1 = stat(a1, &v3) != 0;
  result = 0;
  if ( !v1 )
    result = (v3.st_uid & 0xF000) != 0x4000;
  return result;
}

