int __fastcall FBR_MD5Init(_DWORD *a1)
{
  int result; // $v0

  a1[2] = -2025512191;
  a1[3] = -808604791;
  a1[4] = 683334910;
  result = 808604790;
  a1[1] = 0;
  *a1 = 0;
  a1[5] = 808604790;
  return result;
}

