
undefined4 socketGetError(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR___errno_location_00430978)();
  return *puVar1;
}

