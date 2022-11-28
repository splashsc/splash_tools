int sub_41FE70()
{
  int result; // $v0
  unsigned int i; // $v0
  bool v2; // dc
  int v3; // $v0

  result = (unsigned __int8)byte_67D070;
  if ( !byte_67D070 )
  {
    for ( i = dword_67D074; ; i = dword_67D074 )
    {
      v2 = i >= &dword_66523C - dword_665238 - 1;
      v3 = i + 1;
      if ( v2 )
        break;
      dword_67D074 = v3;
      ((void (*)(void))dword_665238[v3])();
    }
    result = 1;
    if ( __deregister_frame_info )
    {
      __deregister_frame_info(&unk_65503C);
      result = 1;
    }
    byte_67D070 = 1;
  }
  return result;
}
// 655070: using guessed type int __fastcall __deregister_frame_info(_DWORD);
// 665238: using guessed type int dword_665238[];
// 66523C: using guessed type int dword_66523C;
// 67D070: using guessed type char byte_67D070;
// 67D074: using guessed type int dword_67D074;

