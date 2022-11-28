int sub_4CC640()
{
  int (**v0)(void); // $s0
  int (*i)(void); // $t9
  int result; // $v0

  v0 = &off_665230;
  for ( i = off_665230; i != (int (*)(void))-1; i = *v0 )
  {
    --v0;
    result = i();
  }
  return result;
}
// 665230: using guessed type int (*off_665230)();

