hello_int: int | string = "hello multi-type"

print| hello_int |

hello_char: int | char = (cast hello_int int)
hello_int = (* (cast hello_int int) 3)

print| "hello_int is" hello_int ", hello_char is" hello_char |

hello_char = 'h'

char_bool: char | bool = hello_char
print| char_bool |

x: char | char | int = char_bool
print| x |

s: string = "hello world"
d: double = 10d
f: float = 9f
i: int = 8
b: bool = true
c: char = 't'

print| "unknown test" |

u: unknown = s
print| "should:" s ", res:" u |

u = d
print| "should:" d ", res:" u |

u = f
print| "should:" f ", res:" u |

u = i
print| "should:" i ", res:" u |

u = b
print| "should:" b ", res:" u |

u = c
print| "should:" c ", res:" u |

char_bool = true
x = char_bool