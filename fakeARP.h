#include <linux/proc_fs.h> //to interact with userspace using procfs
#include <linux/seq_file.h> //print output using procfs
#include <linux/kernel.h> //for printk and other stuff
#include <linux/slab.h> //kmalloc and kfree
 
//TODO: implement locking for this global (for now incoming lock is enough)
//TODO: I don't need to zero these out, they are already in BSS, right?
//very simple hash table implementation
extern struct list_head fake_mac_list[256];

//TODO: what data type kernel uses for IP and MAC internally?
//I used byte arrays since I will be copying from buffers
struct ip_mac_pair {
	u8 ip[4];
	u8 mac[6];
	struct list_head mac_list;
};

struct list_head *hash_fake_mac_list(u8 *ip);
u8 *insert_ip_mac_pair(u8 *ip, u8 *mac);
u8 *insert_new_ip_mac_pair(u8 *ip);
//TODO: put remove function signature here
u8 *get_mac(u8 *ip);
void dump_ip_list(void);
