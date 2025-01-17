PGDMP                       }            TerraCRM    16.2    16.2 �    }           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            ~           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false                       0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            �           1262    33009    TerraCRM    DATABASE     ~   CREATE DATABASE "TerraCRM" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'Russian_Russia.1251';
    DROP DATABASE "TerraCRM";
                postgres    false                        2615    2200    public    SCHEMA        CREATE SCHEMA public;
    DROP SCHEMA public;
                pg_database_owner    false            �           0    0    SCHEMA public    COMMENT     6   COMMENT ON SCHEMA public IS 'standard public schema';
                   pg_database_owner    false    7            .           1255    131872    is_client_account(text)    FUNCTION     ;  CREATE FUNCTION public.is_client_account(rs text) RETURNS boolean
    LANGUAGE plpgsql IMMUTABLE COST 7 PARALLEL SAFE
    SET search_path TO ''
    AS $_$
declare
    digits int[];
    checksum int not null default 0;
    coefficients constant int[] not null default array[7, 1, 3, 7, 1, 3, 7, 1, 3, 7, 1, 3, 7, 1, 3, 7, 1, 3, 7, 1, 3, 7, 1];
    i int default 1;
begin

    --https://ru.wikipedia.org/wiki/Расчётный_счёт
    --https://cbr.ru/na/385-p/ Положение Банка России «О правилах ведения бухгалтерского учета в кредитных организациях, расположенных на территории Российской Федерации» № 385-П от 16.07.2012
    if rs is null then
        return null;
    elsif octet_length(rs) != 20
        or rs ~ '\D'
        or rs ~ '^([1-9])\1+$'
    then
        return false;
    end if;

    --https://ru.wikipedia.org/wiki/Контрольное_число#Расчет_контрольного_числа
    --http://www.consultant.ru/document/cons_doc_LAW_16053/08c1d0eacf880db80ef56f68c3469e2ea24502d7/
    while coefficients[i] is not null
    loop
        checksum := checksum + coefficients[i] * (digits[i] % 10);
        i := i + 1;
    end loop;

    return checksum % 10 = 0;

end;
$_$;
 1   DROP FUNCTION public.is_client_account(rs text);
       public          postgres    false    7            �           0    0 #   FUNCTION is_client_account(rs text)    COMMENT     �   COMMENT ON FUNCTION public.is_client_account(rs text) IS 'Проверяет, что переданная строка является расчётным счётом';
          public          postgres    false    302            �           1247    131874    client_account    DOMAIN     v   CREATE DOMAIN public.client_account AS text
	CONSTRAINT client_account_check CHECK (public.is_client_account(VALUE));
 #   DROP DOMAIN public.client_account;
       public          postgres    false    302    7            �           0    0    DOMAIN client_account    COMMENT     J   COMMENT ON DOMAIN public.client_account IS 'Расчётный счёт';
          public          postgres    false    940            �            1259    33020    users    TABLE       CREATE TABLE public.users (
    id integer NOT NULL,
    hashedpassword text NOT NULL,
    login text NOT NULL,
    salt text NOT NULL,
    role text NOT NULL,
    name text NOT NULL,
    surname text NOT NULL,
    phone bigint NOT NULL,
    company_id integer NOT NULL
);
    DROP TABLE public.users;
       public         heap    postgres    false    7            �            1259    33019    Users_id_seq    SEQUENCE     �   CREATE SEQUENCE public."Users_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public."Users_id_seq";
       public          postgres    false    7    218            �           0    0    Users_id_seq    SEQUENCE OWNED BY     ?   ALTER SEQUENCE public."Users_id_seq" OWNED BY public.users.id;
          public          postgres    false    217            �            1259    131877    accounts    TABLE     �   CREATE TABLE public.accounts (
    id integer NOT NULL,
    company_id integer NOT NULL,
    name text NOT NULL,
    balance numeric(15,2) NOT NULL
);
    DROP TABLE public.accounts;
       public         heap    postgres    false    7            �            1259    131876    accounts_accountid_seq    SEQUENCE     �   CREATE SEQUENCE public.accounts_accountid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 -   DROP SEQUENCE public.accounts_accountid_seq;
       public          postgres    false    236    7            �           0    0    accounts_accountid_seq    SEQUENCE OWNED BY     J   ALTER SEQUENCE public.accounts_accountid_seq OWNED BY public.accounts.id;
          public          postgres    false    235            �            1259    131942    articleEvent    TABLE     [   CREATE TABLE public."articleEvent" (
    id integer NOT NULL,
    article text NOT NULL
);
 "   DROP TABLE public."articleEvent";
       public         heap    postgres    false    7            �            1259    131941    articleEvent_id_seq    SEQUENCE     �   CREATE SEQUENCE public."articleEvent_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 ,   DROP SEQUENCE public."articleEvent_id_seq";
       public          postgres    false    240    7            �           0    0    articleEvent_id_seq    SEQUENCE OWNED BY     O   ALTER SEQUENCE public."articleEvent_id_seq" OWNED BY public."articleEvent".id;
          public          postgres    false    239            �            1259    131903 
   categories    TABLE     T   CREATE TABLE public.categories (
    id integer NOT NULL,
    name text NOT NULL
);
    DROP TABLE public.categories;
       public         heap    postgres    false    7            �            1259    131902    categories_categoryid_seq    SEQUENCE     �   CREATE SEQUENCE public.categories_categoryid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 0   DROP SEQUENCE public.categories_categoryid_seq;
       public          postgres    false    7    238            �           0    0    categories_categoryid_seq    SEQUENCE OWNED BY     O   ALTER SEQUENCE public.categories_categoryid_seq OWNED BY public.categories.id;
          public          postgres    false    237            �            1259    230339    categoryClients    TABLE     _   CREATE TABLE public."categoryClients" (
    id integer NOT NULL,
    category text NOT NULL
);
 %   DROP TABLE public."categoryClients";
       public         heap    postgres    false    7            �            1259    230342    categoryClients_id_seq    SEQUENCE     �   CREATE SEQUENCE public."categoryClients_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 /   DROP SEQUENCE public."categoryClients_id_seq";
       public          postgres    false    241    7            �           0    0    categoryClients_id_seq    SEQUENCE OWNED BY     U   ALTER SEQUENCE public."categoryClients_id_seq" OWNED BY public."categoryClients".id;
          public          postgres    false    242            �            1259    254928    communication_channel    TABLE     _   CREATE TABLE public.communication_channel (
    id integer NOT NULL,
    name text NOT NULL
);
 )   DROP TABLE public.communication_channel;
       public         heap    postgres    false    7            �            1259    254927    communication_channel_id_seq    SEQUENCE     �   CREATE SEQUENCE public.communication_channel_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 3   DROP SEQUENCE public.communication_channel_id_seq;
       public          postgres    false    244    7            �           0    0    communication_channel_id_seq    SEQUENCE OWNED BY     ]   ALTER SEQUENCE public.communication_channel_id_seq OWNED BY public.communication_channel.id;
          public          postgres    false    243            �            1259    74349 	   companies    TABLE     �   CREATE TABLE public.companies (
    id integer NOT NULL,
    name text NOT NULL,
    phone bigint NOT NULL,
    email text NOT NULL,
    category integer NOT NULL,
    site text
);
    DROP TABLE public.companies;
       public         heap    postgres    false    7            �            1259    74377    contacts    TABLE     �   CREATE TABLE public.contacts (
    id integer NOT NULL,
    name text NOT NULL,
    phone bigint NOT NULL,
    email text NOT NULL,
    category integer,
    surname text,
    patronymic text,
    birth date
);
    DROP TABLE public.contacts;
       public         heap    postgres    false    7            �            1259    74376    contacts_id_seq    SEQUENCE     �   CREATE SEQUENCE public.contacts_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.contacts_id_seq;
       public          postgres    false    228    7            �           0    0    contacts_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.contacts_id_seq OWNED BY public.contacts.id;
          public          postgres    false    227            �            1259    74348    counterpars_id_seq    SEQUENCE     �   CREATE SEQUENCE public.counterpars_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 )   DROP SEQUENCE public.counterpars_id_seq;
       public          postgres    false    7    226            �           0    0    counterpars_id_seq    SEQUENCE OWNED BY     G   ALTER SEQUENCE public.counterpars_id_seq OWNED BY public.companies.id;
          public          postgres    false    225            �            1259    57884    deals    TABLE     b  CREATE TABLE public.deals (
    id integer NOT NULL,
    "nameDeal" text NOT NULL,
    cost integer NOT NULL,
    "dateBegin" date NOT NULL,
    "dateEnd" date NOT NULL,
    status text NOT NULL,
    "sourceDeal" text NOT NULL,
    responsible integer NOT NULL,
    customer integer NOT NULL,
    "completedDate" date,
    company_id integer NOT NULL
);
    DROP TABLE public.deals;
       public         heap    postgres    false    7            �            1259    57883    deals_id_seq    SEQUENCE     �   CREATE SEQUENCE public.deals_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 #   DROP SEQUENCE public.deals_id_seq;
       public          postgres    false    7    222            �           0    0    deals_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.deals_id_seq OWNED BY public.deals.id;
          public          postgres    false    221            �            1259    74408    executorsProjects    TABLE     �   CREATE TABLE public."executorsProjects" (
    executor integer NOT NULL,
    project integer NOT NULL,
    id integer NOT NULL
);
 '   DROP TABLE public."executorsProjects";
       public         heap    postgres    false    7            �            1259    74421    executorsProjects_id_seq    SEQUENCE     �   CREATE SEQUENCE public."executorsProjects_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 1   DROP SEQUENCE public."executorsProjects_id_seq";
       public          postgres    false    229    7            �           0    0    executorsProjects_id_seq    SEQUENCE OWNED BY     Y   ALTER SEQUENCE public."executorsProjects_id_seq" OWNED BY public."executorsProjects".id;
          public          postgres    false    230            �            1259    123631    finance    TABLE     w  CREATE TABLE public.finance (
    id integer NOT NULL,
    date date NOT NULL,
    cash integer NOT NULL,
    payer integer NOT NULL,
    recipient integer NOT NULL,
    communication integer NOT NULL,
    responsible integer NOT NULL,
    note text,
    category integer NOT NULL,
    account integer NOT NULL,
    state integer NOT NULL,
    company_id integer NOT NULL
);
    DROP TABLE public.finance;
       public         heap    postgres    false    7            �            1259    123630    finance_id_seq    SEQUENCE     �   CREATE SEQUENCE public.finance_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.finance_id_seq;
       public          postgres    false    232    7            �           0    0    finance_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.finance_id_seq OWNED BY public.finance.id;
          public          postgres    false    231            �            1259    74282    project    TABLE     e  CREATE TABLE public.project (
    id integer NOT NULL,
    name text NOT NULL,
    status text NOT NULL,
    stage text NOT NULL,
    "dateBegin" date NOT NULL,
    receipt bigint,
    debit bigint,
    profit bigint,
    manager integer,
    deadline date NOT NULL,
    "completedDate" date,
    client integer NOT NULL,
    company_id integer NOT NULL
);
    DROP TABLE public.project;
       public         heap    postgres    false    7            �            1259    74281    project_id_seq    SEQUENCE     �   CREATE SEQUENCE public.project_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.project_id_seq;
       public          postgres    false    224    7            �           0    0    project_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.project_id_seq OWNED BY public.project.id;
          public          postgres    false    223            �            1259    33113    tasks    TABLE     �  CREATE TABLE public.tasks (
    id integer NOT NULL,
    "nameTask" text NOT NULL,
    "statusTask" text NOT NULL,
    "creatorTask" integer NOT NULL,
    "executorTask" integer,
    "dateCreate" date NOT NULL,
    priority text NOT NULL,
    "dateBegin" date,
    "dateDeadline" date NOT NULL,
    "completedDate" date,
    project integer NOT NULL,
    company_id integer NOT NULL
);
    DROP TABLE public.tasks;
       public         heap    postgres    false    7            �            1259    57708    tasks_id_seq    SEQUENCE     �   CREATE SEQUENCE public.tasks_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 #   DROP SEQUENCE public.tasks_id_seq;
       public          postgres    false    219    7            �           0    0    tasks_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.tasks_id_seq OWNED BY public.tasks.id;
          public          postgres    false    220            �            1259    131850 	   transfers    TABLE       CREATE TABLE public.transfers (
    id integer NOT NULL,
    date date NOT NULL,
    cash integer NOT NULL,
    responsible integer NOT NULL,
    "from" integer NOT NULL,
    "to" integer NOT NULL,
    state integer NOT NULL,
    company_id integer NOT NULL
);
    DROP TABLE public.transfers;
       public         heap    postgres    false    7            �            1259    131849    transfers_id_seq    SEQUENCE     �   CREATE SEQUENCE public.transfers_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 '   DROP SEQUENCE public.transfers_id_seq;
       public          postgres    false    234    7            �           0    0    transfers_id_seq    SEQUENCE OWNED BY     E   ALTER SEQUENCE public.transfers_id_seq OWNED BY public.transfers.id;
          public          postgres    false    233            �           2604    131880    accounts id    DEFAULT     q   ALTER TABLE ONLY public.accounts ALTER COLUMN id SET DEFAULT nextval('public.accounts_accountid_seq'::regclass);
 :   ALTER TABLE public.accounts ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    236    235    236            �           2604    131945    articleEvent id    DEFAULT     v   ALTER TABLE ONLY public."articleEvent" ALTER COLUMN id SET DEFAULT nextval('public."articleEvent_id_seq"'::regclass);
 @   ALTER TABLE public."articleEvent" ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    239    240    240            �           2604    131906    categories id    DEFAULT     v   ALTER TABLE ONLY public.categories ALTER COLUMN id SET DEFAULT nextval('public.categories_categoryid_seq'::regclass);
 <   ALTER TABLE public.categories ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    237    238    238            �           2604    230343    categoryClients id    DEFAULT     |   ALTER TABLE ONLY public."categoryClients" ALTER COLUMN id SET DEFAULT nextval('public."categoryClients_id_seq"'::regclass);
 C   ALTER TABLE public."categoryClients" ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    242    241            �           2604    254931    communication_channel id    DEFAULT     �   ALTER TABLE ONLY public.communication_channel ALTER COLUMN id SET DEFAULT nextval('public.communication_channel_id_seq'::regclass);
 G   ALTER TABLE public.communication_channel ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    243    244    244            �           2604    74352    companies id    DEFAULT     n   ALTER TABLE ONLY public.companies ALTER COLUMN id SET DEFAULT nextval('public.counterpars_id_seq'::regclass);
 ;   ALTER TABLE public.companies ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    226    225    226            �           2604    74380    contacts id    DEFAULT     j   ALTER TABLE ONLY public.contacts ALTER COLUMN id SET DEFAULT nextval('public.contacts_id_seq'::regclass);
 :   ALTER TABLE public.contacts ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    227    228    228            �           2604    57887    deals id    DEFAULT     d   ALTER TABLE ONLY public.deals ALTER COLUMN id SET DEFAULT nextval('public.deals_id_seq'::regclass);
 7   ALTER TABLE public.deals ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    221    222    222            �           2604    74422    executorsProjects id    DEFAULT     �   ALTER TABLE ONLY public."executorsProjects" ALTER COLUMN id SET DEFAULT nextval('public."executorsProjects_id_seq"'::regclass);
 E   ALTER TABLE public."executorsProjects" ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    230    229            �           2604    123634 
   finance id    DEFAULT     h   ALTER TABLE ONLY public.finance ALTER COLUMN id SET DEFAULT nextval('public.finance_id_seq'::regclass);
 9   ALTER TABLE public.finance ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    231    232    232            �           2604    74285 
   project id    DEFAULT     h   ALTER TABLE ONLY public.project ALTER COLUMN id SET DEFAULT nextval('public.project_id_seq'::regclass);
 9   ALTER TABLE public.project ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    223    224    224            �           2604    57709    tasks id    DEFAULT     d   ALTER TABLE ONLY public.tasks ALTER COLUMN id SET DEFAULT nextval('public.tasks_id_seq'::regclass);
 7   ALTER TABLE public.tasks ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    220    219            �           2604    131853    transfers id    DEFAULT     l   ALTER TABLE ONLY public.transfers ALTER COLUMN id SET DEFAULT nextval('public.transfers_id_seq'::regclass);
 ;   ALTER TABLE public.transfers ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    233    234    234            �           2604    33023    users id    DEFAULT     f   ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public."Users_id_seq"'::regclass);
 7   ALTER TABLE public.users ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    218    217    218            r          0    131877    accounts 
   TABLE DATA           A   COPY public.accounts (id, company_id, name, balance) FROM stdin;
    public          postgres    false    236   g�       v          0    131942    articleEvent 
   TABLE DATA           5   COPY public."articleEvent" (id, article) FROM stdin;
    public          postgres    false    240   ��       t          0    131903 
   categories 
   TABLE DATA           .   COPY public.categories (id, name) FROM stdin;
    public          postgres    false    238   G�       w          0    230339    categoryClients 
   TABLE DATA           9   COPY public."categoryClients" (id, category) FROM stdin;
    public          postgres    false    241   �       z          0    254928    communication_channel 
   TABLE DATA           9   COPY public.communication_channel (id, name) FROM stdin;
    public          postgres    false    244   \�       h          0    74349 	   companies 
   TABLE DATA           K   COPY public.companies (id, name, phone, email, category, site) FROM stdin;
    public          postgres    false    226   ��       j          0    74377    contacts 
   TABLE DATA           `   COPY public.contacts (id, name, phone, email, category, surname, patronymic, birth) FROM stdin;
    public          postgres    false    228   w�       d          0    57884    deals 
   TABLE DATA           �   COPY public.deals (id, "nameDeal", cost, "dateBegin", "dateEnd", status, "sourceDeal", responsible, customer, "completedDate", company_id) FROM stdin;
    public          postgres    false    222   ��       k          0    74408    executorsProjects 
   TABLE DATA           D   COPY public."executorsProjects" (executor, project, id) FROM stdin;
    public          postgres    false    229   �       n          0    123631    finance 
   TABLE DATA           �   COPY public.finance (id, date, cash, payer, recipient, communication, responsible, note, category, account, state, company_id) FROM stdin;
    public          postgres    false    232   Q�       f          0    74282    project 
   TABLE DATA           �   COPY public.project (id, name, status, stage, "dateBegin", receipt, debit, profit, manager, deadline, "completedDate", client, company_id) FROM stdin;
    public          postgres    false    224   _�       a          0    33113    tasks 
   TABLE DATA           �   COPY public.tasks (id, "nameTask", "statusTask", "creatorTask", "executorTask", "dateCreate", priority, "dateBegin", "dateDeadline", "completedDate", project, company_id) FROM stdin;
    public          postgres    false    219   ��       p          0    131850 	   transfers 
   TABLE DATA           a   COPY public.transfers (id, date, cash, responsible, "from", "to", state, company_id) FROM stdin;
    public          postgres    false    234   s�       `          0    33020    users 
   TABLE DATA           h   COPY public.users (id, hashedpassword, login, salt, role, name, surname, phone, company_id) FROM stdin;
    public          postgres    false    218   Ҧ       �           0    0    Users_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public."Users_id_seq"', 18, true);
          public          postgres    false    217            �           0    0    accounts_accountid_seq    SEQUENCE SET     D   SELECT pg_catalog.setval('public.accounts_accountid_seq', 9, true);
          public          postgres    false    235            �           0    0    articleEvent_id_seq    SEQUENCE SET     C   SELECT pg_catalog.setval('public."articleEvent_id_seq"', 4, true);
          public          postgres    false    239            �           0    0    categories_categoryid_seq    SEQUENCE SET     G   SELECT pg_catalog.setval('public.categories_categoryid_seq', 8, true);
          public          postgres    false    237            �           0    0    categoryClients_id_seq    SEQUENCE SET     F   SELECT pg_catalog.setval('public."categoryClients_id_seq"', 2, true);
          public          postgres    false    242            �           0    0    communication_channel_id_seq    SEQUENCE SET     J   SELECT pg_catalog.setval('public.communication_channel_id_seq', 4, true);
          public          postgres    false    243            �           0    0    contacts_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.contacts_id_seq', 12, true);
          public          postgres    false    227            �           0    0    counterpars_id_seq    SEQUENCE SET     @   SELECT pg_catalog.setval('public.counterpars_id_seq', 7, true);
          public          postgres    false    225            �           0    0    deals_id_seq    SEQUENCE SET     :   SELECT pg_catalog.setval('public.deals_id_seq', 5, true);
          public          postgres    false    221            �           0    0    executorsProjects_id_seq    SEQUENCE SET     I   SELECT pg_catalog.setval('public."executorsProjects_id_seq"', 43, true);
          public          postgres    false    230            �           0    0    finance_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.finance_id_seq', 167, true);
          public          postgres    false    231            �           0    0    project_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.project_id_seq', 35, true);
          public          postgres    false    223            �           0    0    tasks_id_seq    SEQUENCE SET     <   SELECT pg_catalog.setval('public.tasks_id_seq', 132, true);
          public          postgres    false    220            �           0    0    transfers_id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public.transfers_id_seq', 73, true);
          public          postgres    false    233            �           2606    33027    users Users_pkey 
   CONSTRAINT     P   ALTER TABLE ONLY public.users
    ADD CONSTRAINT "Users_pkey" PRIMARY KEY (id);
 <   ALTER TABLE ONLY public.users DROP CONSTRAINT "Users_pkey";
       public            postgres    false    218            �           2606    131882    accounts accounts_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.accounts
    ADD CONSTRAINT accounts_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.accounts DROP CONSTRAINT accounts_pkey;
       public            postgres    false    236            �           2606    131949    articleEvent articleEvent_pkey 
   CONSTRAINT     `   ALTER TABLE ONLY public."articleEvent"
    ADD CONSTRAINT "articleEvent_pkey" PRIMARY KEY (id);
 L   ALTER TABLE ONLY public."articleEvent" DROP CONSTRAINT "articleEvent_pkey";
       public            postgres    false    240            �           2606    131908    categories categories_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_pkey PRIMARY KEY (id);
 D   ALTER TABLE ONLY public.categories DROP CONSTRAINT categories_pkey;
       public            postgres    false    238            �           2606    230350 $   categoryClients categoryClients_pkey 
   CONSTRAINT     f   ALTER TABLE ONLY public."categoryClients"
    ADD CONSTRAINT "categoryClients_pkey" PRIMARY KEY (id);
 R   ALTER TABLE ONLY public."categoryClients" DROP CONSTRAINT "categoryClients_pkey";
       public            postgres    false    241            �           2606    254935 0   communication_channel communication_channel_pkey 
   CONSTRAINT     n   ALTER TABLE ONLY public.communication_channel
    ADD CONSTRAINT communication_channel_pkey PRIMARY KEY (id);
 Z   ALTER TABLE ONLY public.communication_channel DROP CONSTRAINT communication_channel_pkey;
       public            postgres    false    244            �           2606    74384    contacts contacts_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.contacts
    ADD CONSTRAINT contacts_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.contacts DROP CONSTRAINT contacts_pkey;
       public            postgres    false    228            �           2606    74358    companies counterpars_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.companies
    ADD CONSTRAINT counterpars_pkey PRIMARY KEY (id);
 D   ALTER TABLE ONLY public.companies DROP CONSTRAINT counterpars_pkey;
       public            postgres    false    226            �           2606    57891    deals deals_pkey 
   CONSTRAINT     N   ALTER TABLE ONLY public.deals
    ADD CONSTRAINT deals_pkey PRIMARY KEY (id);
 :   ALTER TABLE ONLY public.deals DROP CONSTRAINT deals_pkey;
       public            postgres    false    222            �           2606    74427 (   executorsProjects executorsProjects_pkey 
   CONSTRAINT     j   ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT "executorsProjects_pkey" PRIMARY KEY (id);
 V   ALTER TABLE ONLY public."executorsProjects" DROP CONSTRAINT "executorsProjects_pkey";
       public            postgres    false    229            �           2606    123638    finance finance_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT finance_pkey PRIMARY KEY (id);
 >   ALTER TABLE ONLY public.finance DROP CONSTRAINT finance_pkey;
       public            postgres    false    232            �           2606    213949    users login 
   CONSTRAINT     W   ALTER TABLE ONLY public.users
    ADD CONSTRAINT login UNIQUE (login) INCLUDE (login);
 5   ALTER TABLE ONLY public.users DROP CONSTRAINT login;
       public            postgres    false    218            �           2606    213947    users phone 
   CONSTRAINT     W   ALTER TABLE ONLY public.users
    ADD CONSTRAINT phone UNIQUE (phone) INCLUDE (phone);
 5   ALTER TABLE ONLY public.users DROP CONSTRAINT phone;
       public            postgres    false    218            �           2606    74289    project project_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY public.project
    ADD CONSTRAINT project_pkey PRIMARY KEY (id);
 >   ALTER TABLE ONLY public.project DROP CONSTRAINT project_pkey;
       public            postgres    false    224            �           2606    57716    tasks tasks_pkey 
   CONSTRAINT     N   ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_pkey PRIMARY KEY (id);
 :   ALTER TABLE ONLY public.tasks DROP CONSTRAINT tasks_pkey;
       public            postgres    false    219            �           2606    131857    transfers transfers_pkey 
   CONSTRAINT     V   ALTER TABLE ONLY public.transfers
    ADD CONSTRAINT transfers_pkey PRIMARY KEY (id);
 B   ALTER TABLE ONLY public.transfers DROP CONSTRAINT transfers_pkey;
       public            postgres    false    234            �           2606    131936    finance account    FK CONSTRAINT     {   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT account FOREIGN KEY (account) REFERENCES public.accounts(id) NOT VALID;
 9   ALTER TABLE ONLY public.finance DROP CONSTRAINT account;
       public          postgres    false    236    232    4789            �           2606    131931    finance category    FK CONSTRAINT        ALTER TABLE ONLY public.finance
    ADD CONSTRAINT category FOREIGN KEY (category) REFERENCES public.categories(id) NOT VALID;
 :   ALTER TABLE ONLY public.finance DROP CONSTRAINT category;
       public          postgres    false    4791    232    238            �           2606    230351    contacts category    FK CONSTRAINT     �   ALTER TABLE ONLY public.contacts
    ADD CONSTRAINT category FOREIGN KEY (category) REFERENCES public."categoryClients"(id) NOT VALID;
 ;   ALTER TABLE ONLY public.contacts DROP CONSTRAINT category;
       public          postgres    false    228    4795    241            �           2606    230356    companies category    FK CONSTRAINT     �   ALTER TABLE ONLY public.companies
    ADD CONSTRAINT category FOREIGN KEY (category) REFERENCES public."categoryClients"(id) NOT VALID;
 <   ALTER TABLE ONLY public.companies DROP CONSTRAINT category;
       public          postgres    false    241    226    4795            �           2606    123644    finance connection    FK CONSTRAINT     �   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT connection FOREIGN KEY (communication) REFERENCES public.project(id) NOT VALID;
 <   ALTER TABLE ONLY public.finance DROP CONSTRAINT connection;
       public          postgres    false    224    4777    232            �           2606    131926    accounts counterpar_id    FK CONSTRAINT     �   ALTER TABLE ONLY public.accounts
    ADD CONSTRAINT counterpar_id FOREIGN KEY (company_id) REFERENCES public.companies(id) NOT VALID;
 @   ALTER TABLE ONLY public.accounts DROP CONSTRAINT counterpar_id;
       public          postgres    false    4779    226    236            �           2606    74411    executorsProjects executor    FK CONSTRAINT        ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT executor FOREIGN KEY (executor) REFERENCES public.contacts(id);
 F   ALTER TABLE ONLY public."executorsProjects" DROP CONSTRAINT executor;
       public          postgres    false    228    4781    229            �           2606    57907    tasks fk_creator    FK CONSTRAINT        ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_creator FOREIGN KEY ("creatorTask") REFERENCES public.users(id) NOT VALID;
 :   ALTER TABLE ONLY public.tasks DROP CONSTRAINT fk_creator;
       public          postgres    false    218    4767    219            �           2606    156569    deals fk_customer    FK CONSTRAINT     ~   ALTER TABLE ONLY public.deals
    ADD CONSTRAINT fk_customer FOREIGN KEY (customer) REFERENCES public.contacts(id) NOT VALID;
 ;   ALTER TABLE ONLY public.deals DROP CONSTRAINT fk_customer;
       public          postgres    false    222    4781    228            �           2606    57912    tasks fk_executor    FK CONSTRAINT     �   ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_executor FOREIGN KEY ("executorTask") REFERENCES public.users(id) NOT VALID;
 ;   ALTER TABLE ONLY public.tasks DROP CONSTRAINT fk_executor;
       public          postgres    false    218    4767    219            �           2606    74393    project fk_manager    FK CONSTRAINT     {   ALTER TABLE ONLY public.project
    ADD CONSTRAINT fk_manager FOREIGN KEY (manager) REFERENCES public.users(id) NOT VALID;
 <   ALTER TABLE ONLY public.project DROP CONSTRAINT fk_manager;
       public          postgres    false    224    4767    218            �           2606    74290    tasks fk_project    FK CONSTRAINT     {   ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_project FOREIGN KEY (project) REFERENCES public.project(id) NOT VALID;
 :   ALTER TABLE ONLY public.tasks DROP CONSTRAINT fk_project;
       public          postgres    false    224    4777    219            �           2606    74338    deals fk_responsible    FK CONSTRAINT     �   ALTER TABLE ONLY public.deals
    ADD CONSTRAINT fk_responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;
 >   ALTER TABLE ONLY public.deals DROP CONSTRAINT fk_responsible;
       public          postgres    false    218    4767    222            �           2606    131858    transfers fk_responsible    FK CONSTRAINT     �   ALTER TABLE ONLY public.transfers
    ADD CONSTRAINT fk_responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;
 B   ALTER TABLE ONLY public.transfers DROP CONSTRAINT fk_responsible;
       public          postgres    false    218    234    4767            �           2606    254941    finance payer    FK CONSTRAINT     x   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT payer FOREIGN KEY (payer) REFERENCES public.companies(id) NOT VALID;
 7   ALTER TABLE ONLY public.finance DROP CONSTRAINT payer;
       public          postgres    false    232    4779    226            �           2606    74431    executorsProjects project    FK CONSTRAINT     �   ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT project FOREIGN KEY (project) REFERENCES public.project(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 E   ALTER TABLE ONLY public."executorsProjects" DROP CONSTRAINT project;
       public          postgres    false    4777    229    224            �           2606    123649    finance responsible    FK CONSTRAINT     �   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;
 =   ALTER TABLE ONLY public.finance DROP CONSTRAINT responsible;
       public          postgres    false    4767    218    232            �           2606    131950    finance state    FK CONSTRAINT     }   ALTER TABLE ONLY public.finance
    ADD CONSTRAINT state FOREIGN KEY (state) REFERENCES public."articleEvent"(id) NOT VALID;
 7   ALTER TABLE ONLY public.finance DROP CONSTRAINT state;
       public          postgres    false    232    4793    240            r   �   x�}��� E�e
'0d�ыg0q/&����/��[�>�O5a��8`�=�8b/ޕL�\2��a�%��e���3����I�W�ߚ�t^Ӥ`-���<���Z\zl�f���m��� 5�`      v   @   x�3�0����8/L\�P�
P9�s/lU���bÅ}6]�za������ �i#�      t   �   x�}���0D��*|����r� -X!�@ia�#fC8pᰲw<�v<�p�^(�q�w��)�;��I�#�1Z��΀���Ss��ݙ�����󵦚u�J�2��WD���V��e���X���"�戴/wǩ�n-�,�:Ta�C����Nc�gx��X4j	�m��JCY��+Ճ�RB&]�D��Й      w   2   x�3估���;.l���b��n.#��/l��p����[�t7W� �      z   D   x�3�L�M���2估��֋�/l���ۀ�.c΋M@��@N˅}�r�pU������� "~ �      h   �   x�U�1�0��������nL��,l����xw`<����;<o�&F�t�_����Gw&x�3���O�_{�q�;�+���4Yە:_iktRT�)�����f�Z&`N㖸��HH���ܧ`�@�=�x%%���3kc��&�"X��,�7���U�H>��~9�e����d�1��`�]�      j   u  x�]R�N�0�nߥ��6h��|n* .�͠�x�Í�?�cL|�%����ȯc #������9���'ȋ;���(��t���\LƃI���#��n4"��G1-n��3X�XZ 7�����u�qń���)�-?�J�G�����zM�Csjz�~l�;A���sl�Gh�\@���J0n�:��PȞ(͕t��)MΣ�M���X���ʛuV6&[���]��ъq�I��^�Ǟ�Q`E��	)E�㜜L3���s1-٭ʢ��V��L��W>�f�-��dd�~�Gax�II�W�cw���ⶊ΂�cH�m�o�vIq��6��et}��^����8M��&+���a\2!):���v��?��()      d   �   x����m�0E��^@�$[��K�q�K��1��Fj�j{�ύ���{Lo�H��IF�&\��m�0d����-��pa�&�9'��º`}�����Ī3H��1���A�^��N���x�K�uQ�)�Y��H�uO���i�W�4\�șv:	qe��%��afs��ކJ6f��(v>����0��\m"��xH���D�M�|�����^��Fm�K̳u���|�]Z~�P=���jo��1���      k   <   x�%���0B��G���^�7����MB���2�4�nw���ɹYϘ��C���	�      n   �   x�}бq�0��"0G�(.�	<�/��쐻l�"�rqV�62DД�H�t'>���@���)'{�A� A���ޖ����~L�a�<B̭@�d���d�J��F0n�A�ZۗP�Q녍���Q��n�p�)�T�^|,l\��=mi��������]�/�9��^>,�*8�ګ)&�I<���ci+b31��#TFX���D�)��1�:+�w��D[��o��.]�C5�¾�TB�qe�sOpz!�DSn�      f     x����j�@�ϫ�X|wY���>�^K!i��ZJ��$��d�6���B�P����D����W�}�~3�rPZb��֎f~�}36U�J?�4�U4�)U�.������m�}�����Ώ壚~!Z>T�ؤ�]���៊ӵG�]�R�OT����}���Ψ���l��~�i�e�
�N�[ �qa?��:��t�cAt8N��\<6�o���V>�E�X�'�yJM��@#���T%A�7)s�l�Lѩ�;G��������bg�_v:���,�S��Cʓ�9�ƕD퇷��������~���#�j,S����b2p�D�R1"���>G��F%,	�j&�:n�+wB:��g�D��>i�C�ӥ�ҙش��<����`6��8��4����l�?��G��o��+J�u���b��Ħk�D�>I}�D�H�H5���Ws�3��k:^���o�� �!�������T�bY��y���?�Ds:�aF�Z��(�ļ���o�
�T'�5>�1>��(��LH5      a   �  x��Um��0�mN���$�DO���G�n�_UT�R�ն�X�(�l�\a|����!Ҵ?���̛���JЂ�he&fJ��6���؅gcB*BZRI��T����p��r35�B)T��(N#)"��uɿ�K�E��a��P#!-}����j��' #��q���(T�3��m8�bY�q�^$�K��PoXa��Y�,�r*��$�I7p��6��DhU͡��(��j����5-��)�ě�Az���e4z����p��ښim�^�Q��)��ڦ"P�'��u��>�����38�ҹ�/��q�@i��	�e#�e�A����gP]�A����̑��_�4�mϗG�����Қ}�}�[ϖ����D��3�X�Ι���k\qM��/k.Y�s�M8��M�И�D��������֔*�����|�P�C���(@��씷t�L�w-NyW_�9����.��"lL��K{`9�Q{�i�Z;Xϴj(/Y�v0��xsXWXU�<�[mס[�p��ޙ��=<e� ��ڻж��<���?Iq[=�v��{s�S�V�Xy��;lū��� �s��vl�kh�6��f�g��ݬ�[H*쥯�;�������b>��e͝�����%v����RS��bS�g��#0_l�Waɩqxs�a��{��$�Ӳ=[��s�ĥ}�� ��8Z>X}v���L�����:tm�G��,�z\���;QPc      p   O   x�}���0C�s�KQ��f���B%@�p���[�[x�B���--��V�O�����N	��n�:K�p��$�P?�n�-�w      `   2  x�mR�n�@]���k�=6�x��j�		���5��`�JR��v�V�TU��.���H�h���?�i�.�i�=��.F<��^%4"o�3�Y���t���w*Z�� �~�Y�[��>�:���%��\"�K������X��[XPp���\�ds�"b�q25�WI��2��Lj�$<|���".5��T��7���a�sS��Î��	���I�W����)�B���K���DE�S� Qԅ�#��ޱ��]��%Q9b���LSD����ip4�t���B��e�wz�����������W
��+
��{D�])L�P�JQ�,Qd	Kl�@Z5#���s�-��C렠׌	��Q]@}����(O��}�S������*y��l�w`�|�8KeEC�TB,I2�H�pZA� USl��F߶z�Ag�;�DN�,��/��;yQ-�[���s���|1c���}jt����__�Y�"�A��ӽ�u�YDUd�8-�t�@��=>����JhWâ����07���A�=��������w��`��'M�5]�k�~i��B�8�'1G     