#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <xtables.h>
#include "xt_domain.h"

static void help(void)
{
	printf(
	"domain v%s options:\n"
	"  --name \"www.chinaunix.net\"            Match the domain named \"www.chinaunix.net\"\n"
	"  --name \"chinaunix.net\"                Match the domain named \"chinaunix.net\"\n"
	"                                        include www.chinunix.net, bbs.chinaunix.net, man.chinaunix.net\n",
	DOMAIN_VERSION);
}

static struct option opts[] = {
	{ "name", 1, 0, '1' },
	{ 0 }
};

static void
domain_mt_init (struct xt_entry_match *match)
{
    struct xt_domain_info *info = (void *)match->data;

	printf("domain_mt_init run over !\n") ;

}


static void
parse_name (char *name, struct xt_domain_info *info)
{

	printf("parse run start !\n") ;

	/*

	int i = 0 , char_len = 0;
	int len = strlen(name);

	if (len + 1 > MAX_CHAR)
		xtables_error(PARAMETER_PROBLEM,
			   "The strings `%s' is too long (MAX_CHAR = %d",
			   name, MAX_CHAR);

	printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;

	memcpy(info->name + 1, name, len);
	memcpy(info->org_name, name, len);

	printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;
	info->name[0] = '.';

	for (i = len; i >= 0; i--) {
		if (info->name[i] == '.') {
			info->name[i] = char_len;
			char_len = 0;
		} else {
			char_len++;
		}
	}

	info->len = len + 1;

	 */
	printf("parse_name input parameter name is %s\n",name) ;
	printf("parse run over !\n") ;
}

static int
parse (int c, char **argv, int invert, unsigned int *flags,
       const void *entry, struct xt_entry_match **match)
{

	printf("parse run start !\n") ;

	struct xt_domain_info *info = (struct xt_domain_info *)(*match)->data;

	xtables_check_inverse(optarg, &invert, &optind, 0, argv);

	switch (c) {
		case '1':
			printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;
			parse_name(argv[optind - 1], info);
			*flags = 1;
			break;

		default:
			return 0;
	}

	printf("parse run over !\n") ;

	return 1;
}


static void
domain_check (unsigned int flags)
{
	printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;
	if (flags == 0){
		xtables_error(PARAMETER_PROBLEM, "domain expection an option");
	}
}


static void
print (const void *ip, const struct xt_entry_match *match, int numeric)
{
	printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;
	const struct xt_domain_info *info = (const struct xt_domain_info *)match->data;

	printf("domain --name \"%s\"", info->org_name);
}

static void
save (const void *ip, const struct xt_entry_match *match)
{

	const struct xt_domain_info *info = (const struct xt_domain_info *)match->data;

	printf("--name \"%s\" ", info->org_name);
}

static struct xtables_match domain = {
	.name		= "domain",
	.version	= XTABLES_VERSION,
	.family = NFPROTO_IPV4,
	.size		= XT_ALIGN(sizeof(struct xt_domain_info)),
	.userspacesize	= XT_ALIGN(sizeof(struct xt_domain_info)),
	.help		= help,
    .init = domain_mt_init,
	.parse		= parse,
	.final_check	= domain_check,
	.print		= print,
	.save		= save,
	.extra_opts	= opts
};

void
_init (void)
{
	printf("run in %s#%s%d\n",__func__,__FILE__,__LINE__) ;
	xtables_register_match(&domain);
	printf("xtables_resister_match run over !\n") ;
}
