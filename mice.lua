local ffi = require'ffi'
local mice = ffi.load'./libmice.so'

ffi.cdef [[

struct input_event {
uint8_t time[8];
uint16_t type;
uint16_t code;
int32_t value;
};

int open_mice(void);
void close_mice(int fd);
struct input_event* read_event(int fd);

]]

local fd = mice.open_mice()
while (true)
do
  evt = mice.read_event(fd)
  print('type:'..evt.type..',code:'..evt.code..',val:'..evt.value)
  if ( evt.value ~= 589826 ) then break end
end

mice.close_mice(fd)

