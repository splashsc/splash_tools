int start()
{
  int v0; // $v0

  v0 = sub_41FE04();
  __asm { dsll    $ra, $at, 23 }
  if ( v0 >= _$AT )
    __trap(0x3F8u);
  return sub_41FE04();
}
// 41FDFC: variable '_$AT' is possibly undefined

