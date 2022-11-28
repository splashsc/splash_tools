char *__fastcall unescape(char *a1)
{
  char *result; // $v0
  int v3; // $v0
  int v4; // [sp+18h] [-Ch] BYREF

  while ( 1 )
  {
    result = strpbrk(a1, "%+");
    a1 = result;
    if ( !result )
      break;
    v3 = *result;
    if ( v3 == 37 )
    {
      sscanf(a1 + 1, "%02x", &v4);
      *a1 = v4;
      strcpy(a1 + 1, a1 + 3);
      ++a1;
    }
    else if ( v3 == 43 )
    {
      ++a1;
    }
  }
  return result;
}

