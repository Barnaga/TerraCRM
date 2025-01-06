--
-- PostgreSQL database dump
--

-- Dumped from database version 16.2
-- Dumped by pg_dump version 16.2

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: pgcrypto; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS pgcrypto WITH SCHEMA public;


--
-- Name: EXTENSION pgcrypto; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION pgcrypto IS 'cryptographic functions';


--
-- Name: system_stats; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS system_stats WITH SCHEMA public;


--
-- Name: EXTENSION system_stats; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION system_stats IS 'EnterpriseDB system statistics for PostgreSQL';


--
-- Name: is_client_account(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.is_client_account(rs text) RETURNS boolean
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


ALTER FUNCTION public.is_client_account(rs text) OWNER TO postgres;

--
-- Name: FUNCTION is_client_account(rs text); Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON FUNCTION public.is_client_account(rs text) IS 'Проверяет, что переданная строка является расчётным счётом';


--
-- Name: client_account; Type: DOMAIN; Schema: public; Owner: postgres
--

CREATE DOMAIN public.client_account AS text
	CONSTRAINT client_account_check CHECK (public.is_client_account(VALUE));


ALTER DOMAIN public.client_account OWNER TO postgres;

--
-- Name: DOMAIN client_account; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON DOMAIN public.client_account IS 'Расчётный счёт';


SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
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


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: Users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Users_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public."Users_id_seq" OWNER TO postgres;

--
-- Name: Users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Users_id_seq" OWNED BY public.users.id;


--
-- Name: accounts; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.accounts (
    id integer NOT NULL,
    company_id integer NOT NULL,
    name text NOT NULL,
    balance numeric(15,2) NOT NULL
);


ALTER TABLE public.accounts OWNER TO postgres;

--
-- Name: accounts_accountid_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.accounts_accountid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.accounts_accountid_seq OWNER TO postgres;

--
-- Name: accounts_accountid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.accounts_accountid_seq OWNED BY public.accounts.id;


--
-- Name: articleEvent; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."articleEvent" (
    id integer NOT NULL,
    article text NOT NULL
);


ALTER TABLE public."articleEvent" OWNER TO postgres;

--
-- Name: articleEvent_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."articleEvent_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public."articleEvent_id_seq" OWNER TO postgres;

--
-- Name: articleEvent_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."articleEvent_id_seq" OWNED BY public."articleEvent".id;


--
-- Name: categories; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.categories (
    id integer NOT NULL,
    name text NOT NULL
);


ALTER TABLE public.categories OWNER TO postgres;

--
-- Name: categories_categoryid_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.categories_categoryid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.categories_categoryid_seq OWNER TO postgres;

--
-- Name: categories_categoryid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.categories_categoryid_seq OWNED BY public.categories.id;


--
-- Name: companies; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.companies (
    id integer NOT NULL,
    name text NOT NULL,
    phone bigint,
    email text NOT NULL
);


ALTER TABLE public.companies OWNER TO postgres;

--
-- Name: contacts; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.contacts (
    id integer NOT NULL,
    name text NOT NULL,
    phone bigint NOT NULL,
    email text NOT NULL
);


ALTER TABLE public.contacts OWNER TO postgres;

--
-- Name: contacts_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.contacts_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.contacts_id_seq OWNER TO postgres;

--
-- Name: contacts_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.contacts_id_seq OWNED BY public.contacts.id;


--
-- Name: counterpars_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.counterpars_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.counterpars_id_seq OWNER TO postgres;

--
-- Name: counterpars_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.counterpars_id_seq OWNED BY public.companies.id;


--
-- Name: deals; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.deals (
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


ALTER TABLE public.deals OWNER TO postgres;

--
-- Name: deals_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.deals_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.deals_id_seq OWNER TO postgres;

--
-- Name: deals_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.deals_id_seq OWNED BY public.deals.id;


--
-- Name: executorsProjects; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."executorsProjects" (
    executor integer NOT NULL,
    project integer NOT NULL,
    id integer NOT NULL
);


ALTER TABLE public."executorsProjects" OWNER TO postgres;

--
-- Name: executorsProjects_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."executorsProjects_id_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public."executorsProjects_id_seq" OWNER TO postgres;

--
-- Name: executorsProjects_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."executorsProjects_id_seq" OWNED BY public."executorsProjects".id;


--
-- Name: finance; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.finance (
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
    company_id integer
);


ALTER TABLE public.finance OWNER TO postgres;

--
-- Name: finance_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.finance_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.finance_id_seq OWNER TO postgres;

--
-- Name: finance_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.finance_id_seq OWNED BY public.finance.id;


--
-- Name: project; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.project (
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
    client integer,
    company_id integer NOT NULL
);


ALTER TABLE public.project OWNER TO postgres;

--
-- Name: project_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.project_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.project_id_seq OWNER TO postgres;

--
-- Name: project_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.project_id_seq OWNED BY public.project.id;


--
-- Name: tasks; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.tasks (
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


ALTER TABLE public.tasks OWNER TO postgres;

--
-- Name: tasks_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.tasks_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.tasks_id_seq OWNER TO postgres;

--
-- Name: tasks_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.tasks_id_seq OWNED BY public.tasks.id;


--
-- Name: transfers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.transfers (
    id integer NOT NULL,
    date date NOT NULL,
    cash integer NOT NULL,
    responsible integer NOT NULL,
    "from" integer NOT NULL,
    "to" integer NOT NULL,
    state integer NOT NULL,
    company_id integer NOT NULL
);


ALTER TABLE public.transfers OWNER TO postgres;

--
-- Name: transfers_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.transfers_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.transfers_id_seq OWNER TO postgres;

--
-- Name: transfers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.transfers_id_seq OWNED BY public.transfers.id;


--
-- Name: accounts id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accounts ALTER COLUMN id SET DEFAULT nextval('public.accounts_accountid_seq'::regclass);


--
-- Name: articleEvent id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."articleEvent" ALTER COLUMN id SET DEFAULT nextval('public."articleEvent_id_seq"'::regclass);


--
-- Name: categories id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories ALTER COLUMN id SET DEFAULT nextval('public.categories_categoryid_seq'::regclass);


--
-- Name: companies id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.companies ALTER COLUMN id SET DEFAULT nextval('public.counterpars_id_seq'::regclass);


--
-- Name: contacts id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.contacts ALTER COLUMN id SET DEFAULT nextval('public.contacts_id_seq'::regclass);


--
-- Name: deals id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.deals ALTER COLUMN id SET DEFAULT nextval('public.deals_id_seq'::regclass);


--
-- Name: executorsProjects id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."executorsProjects" ALTER COLUMN id SET DEFAULT nextval('public."executorsProjects_id_seq"'::regclass);


--
-- Name: finance id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance ALTER COLUMN id SET DEFAULT nextval('public.finance_id_seq'::regclass);


--
-- Name: project id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.project ALTER COLUMN id SET DEFAULT nextval('public.project_id_seq'::regclass);


--
-- Name: tasks id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks ALTER COLUMN id SET DEFAULT nextval('public.tasks_id_seq'::regclass);


--
-- Name: transfers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.transfers ALTER COLUMN id SET DEFAULT nextval('public.transfers_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public."Users_id_seq"'::regclass);


--
-- Data for Name: accounts; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.accounts (id, company_id, name, balance) FROM stdin;
7	5	Расчетный счет	299000.00
8	6	Наличные	2999000.00
9	6	Расчетный счет	99000.00
6	5	Наличные	19000.00
2	7	Расчетный счет	26000.00
3	7	Наличные	20000.00
4	1	Расчетный счет	98000.00
5	1	Наличные	198000.00
\.


--
-- Data for Name: articleEvent; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."articleEvent" (id, article) FROM stdin;
1	ПиУ
2	ДДС
3	ДДС и ПиУ
4	Не проведен
\.


--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.categories (id, name) FROM stdin;
1	Продажа товаров
2	Нераспределенные
3	Проценты к получению
4	Получение кредита
5	Оказание услуг
6	Прочий доход
7	Перевод между счетами (поступления)
8	Нераспределенная сумма
\.


--
-- Data for Name: companies; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.companies (id, name, phone, email) FROM stdin;
1	ООО Развлечение	89996575435	rasvlechenie@gmail.com
7	RedFaction	89995896401	redFaction@ya.ru
5	Nails	89612344756	nails@gmail.com
6	Викинг	89512345891	viking@gmail.com
\.


--
-- Data for Name: contacts; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.contacts (id, name, phone, email) FROM stdin;
1	Антон	89912315151	surguchev@gmail.com
2	Виктория	89124513456	vikafadeeva@mail.com
3	Полина	89082394589	polinanikolaeva@gmail.com
4	Дмитрий	83512217500	bulakov@gmail.com
6	Алексей	89082394008	nikolaev.toyworld@gmail.com
5	Анна	83512217512	marininAnna@gmail.com
\.


--
-- Data for Name: deals; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.deals (id, "nameDeal", cost, "dateBegin", "dateEnd", status, "sourceDeal", responsible, customer, "completedDate", company_id) FROM stdin;
5	Покрытие гель-лаком	5000	2024-02-14	2024-07-23	Завершить сделку	Таргет	1	5	2024-09-05	5
4	Индивидуальная тренировка	2500	2024-02-01	2024-08-23	Завершить сделку	Таргет	1	6	2024-11-28	6
3	Замена задней оси	75000	2024-03-04	2024-08-23	Согласование договора	Звонок	1	3	\N	7
2	Принятие решения	35000	2024-07-12	2024-07-28	Принятие решения	Звонок	1	1	2024-12-05	7
\.


--
-- Data for Name: executorsProjects; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."executorsProjects" (executor, project, id) FROM stdin;
1	1	1
4	2	2
5	3	3
3	4	4
1	2	25
3	2	26
1	2	28
1	1	29
1	1	30
1	1	34
\.


--
-- Data for Name: finance; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.finance (id, date, cash, payer, recipient, communication, responsible, note, category, account, state, company_id) FROM stdin;
3	2024-10-22	50000	5	6	2	1	Срочно	2	2	4	5
4	2024-10-21	-30000	6	5	4	1	\N	3	8	2	6
96	2024-11-16	-1000	7	1	1	3		1	2	1	7
97	2024-11-16	20000	1	7	1	3		1	2	1	1
98	2024-11-27	-1000	7	5	3	1		1	2	1	7
1	2024-10-22	123000	6	7	26	1	\N	1	3	1	6
5	2024-10-19	15000	5	7	3	1	Оплата аренды	4	7	3	5
99	2024-12-01	-10000	7	1	2	3		6	2	1	7
102	2024-12-03	-1000	7	1	2	3		1	7	1	7
103	2024-12-03	-1000	7	1	2	3		1	8	1	7
111	2024-07-12	-2000	1	7	30	1	\N	5	2	1	7
121	2024-12-11	-2000	2	7	26	1	\N	5	2	1	7
\.


--
-- Data for Name: project; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.project (id, name, status, stage, "dateBegin", receipt, debit, profit, manager, deadline, "completedDate", client, company_id) FROM stdin;
25	Расширение зала	Просрочен	Проектирование	2024-11-27	300000	150000	150000	1	2025-01-01	\N	6	6
29	Свадьба "Никиты и Светы Бараковых" 	Просрочен	Подготовка	2024-12-01	1000000	300000	700000	1	2025-01-01	\N	1	1
31	Замена подвески	Просрочен	Подготовка	2024-12-05	450000	2000	\N	1	2025-01-01	\N	1	7
3	Покраска "Toyota Camry"	Закрыт успешно	Завершение	2024-09-01	250000	150000	100000	1	2024-10-21	2024-09-10	5	7
1	Бронепленка на "Audi SQ7"	Закрыт успешно	Завершение	2024-06-11	450000	265000	370000	1	2024-09-11	2024-09-10	4	7
30	Тюнинг выхлопной системы	Просрочен	Подготовка	2024-12-05	150000	4000	\N	1	2025-02-01	\N	1	7
26	Бронепленка на "Reno Logan"	Просрочен	Коррекция	2024-11-27	250000	154000	100000	1	2025-01-01	\N	2	7
2	Классический маникюр для Веры	Просрочен	Разработка	2024-08-11	5000	500	4500	1	2024-09-20	\N	1	5
4	День Рождение Юры	Закрыт успешно	Завершение	2024-06-11	300000	55000	245000	1	2024-10-05	2024-11-27	3	1
\.


--
-- Data for Name: tasks; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.tasks (id, "nameTask", "statusTask", "creatorTask", "executorTask", "dateCreate", priority, "dateBegin", "dateDeadline", "completedDate", project, company_id) FROM stdin;
2	Внести изменения в договор	Сделать	3	1	2024-05-11	средний	2024-05-12	2024-05-12	2024-08-23	29	1
31	Заключить договор	Сделать	3	13	2024-05-29	высокий	2024-06-01	2024-06-07	\N	4	1
4	Уточнить время встречи 	Сделать	3	13	2024-04-14	высокий	2024-04-20	2024-04-28	\N	2	5
32	Заказать расходники	Сделать	3	3	2024-06-03	низкий	2024-06-04	2024-06-11	2024-06-09	2	5
33	Разработать проект	Сделать	3	1	2024-06-29	высокий	2024-07-02	2024-07-14	2024-08-23	25	6
126	Купить бронепленку	Сделать	1	12	2024-02-29	средний	2024-03-03	2024-03-10	\N	26	7
127	Произвести покраску	Сделать	1	1	2024-12-05	Высокий	2024-12-05	2024-12-08	\N	3	7
1	Произвести замеры кузова	Архивировано	3	1	2024-03-01	низкий	2024-03-01	2024-03-12	\N	1	7
34	Заказать лак	Завершено	3	1	2024-06-01	высокий	2024-06-04	2024-07-14	2024-08-23	3	7
3	Купить бронепленку	Архивировано	1	12	2024-02-29	средний	2024-03-03	2024-03-10	\N	1	7
122	Провести анализ трендовых цветов в этом месяце	В работе	1	1	2024-11-25	Низкий	2024-11-25	2024-11-27	\N	3	7
5	Купить расходники	Сделать	3	1	2024-04-15	высокий	2024-05-01	2024-05-15	\N	3	7
125	Произвести замеры кузова	Завершено	3	1	2024-03-01	низкий	2024-03-01	2024-03-12	2024-12-30	26	7
35	Заказать шары	Сделать	1	3	2024-06-03	средний	2024-06-05	2024-06-12	\N	4	1
124	Договориться с поставщиком энергетиков	Сделать	1	1	2024-12-01	Низкий	2024-12-01	2024-12-03	\N	25	6
29	Найти строительную бригаду	Сделать	3	12	2024-03-02	средний	2024-03-03	2024-03-10	\N	3	6
30	Сделать оформление зала	Сделать	3	1	2024-04-17	низкий	2024-04-19	2024-04-21	\N	4	1
\.


--
-- Data for Name: transfers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.transfers (id, date, cash, responsible, "from", "to", state, company_id) FROM stdin;
60	2024-11-13	1000	3	2	3	1	7
61	2024-11-13	2000	3	3	2	1	7
62	2024-11-13	10000	3	2	3	1	1
63	2024-11-13	1000	3	2	3	1	1
64	2024-11-13	10000	3	3	2	1	5
65	2024-11-13	1000	3	3	2	1	5
66	2024-11-13	1000	3	2	3	1	7
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, hashedpassword, login, salt, role, name, surname, phone, company_id) FROM stdin;
1	$1$qoGucKO0$cSvkqxg9yiNmoZcpVG7Hg/	1	$1$xgmnYHwq	Директор	Евгений	Барнага	89995896401	7
3	$1$lJH5QAPa$Ix2KI21ljLg101CNuVtSn0	pavlovA@mail.com	$1$qtRV745c	Директор	Алексей	Павлов	89512344356	1
6	$1$00S.Bk2W$oUc8IzfpC04T.woHmuq/N0	KrisBystrTerraCRM@ya.ru	$1$E2pmKSPU	Маркетолог	Кристина	Быстрова	1236785432	5
12	$1$.5PIawnJ$PkXYAyyXlgOASIas1M1vJ.	difail@ya.ru	$1$1tJoaYhp	Продавец	Эльдар	Валеев	76554122311	6
13	$1$/a5Hc0Qx$KdigZCeVqZWGvkAb/F75o/	SemenovIv@gmail.com	$1$Zk4wbEzx	Администратор	Иван	Семенов	89112345643	7
16	$1$ckmr2SSF$v2NxOGuiHuB.QV3wl9yg6/	werdan@ya.ru	$1$u5appEuD	Продавец	Павел	Хлусов	89995895432	7
\.


--
-- Name: Users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Users_id_seq"', 18, true);


--
-- Name: accounts_accountid_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.accounts_accountid_seq', 9, true);


--
-- Name: articleEvent_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."articleEvent_id_seq"', 4, true);


--
-- Name: categories_categoryid_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.categories_categoryid_seq', 8, true);


--
-- Name: contacts_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.contacts_id_seq', 7, true);


--
-- Name: counterpars_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.counterpars_id_seq', 7, true);


--
-- Name: deals_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.deals_id_seq', 5, true);


--
-- Name: executorsProjects_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."executorsProjects_id_seq"', 34, true);


--
-- Name: finance_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.finance_id_seq', 121, true);


--
-- Name: project_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.project_id_seq', 31, true);


--
-- Name: tasks_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.tasks_id_seq', 128, true);


--
-- Name: transfers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.transfers_id_seq', 67, true);


--
-- Name: users Users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT "Users_pkey" PRIMARY KEY (id);


--
-- Name: accounts accounts_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accounts
    ADD CONSTRAINT accounts_pkey PRIMARY KEY (id);


--
-- Name: articleEvent articleEvent_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."articleEvent"
    ADD CONSTRAINT "articleEvent_pkey" PRIMARY KEY (id);


--
-- Name: categories categories_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_pkey PRIMARY KEY (id);


--
-- Name: contacts contacts_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.contacts
    ADD CONSTRAINT contacts_pkey PRIMARY KEY (id);


--
-- Name: companies counterpars_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.companies
    ADD CONSTRAINT counterpars_pkey PRIMARY KEY (id);


--
-- Name: deals deals_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.deals
    ADD CONSTRAINT deals_pkey PRIMARY KEY (id);


--
-- Name: executorsProjects executorsProjects_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT "executorsProjects_pkey" PRIMARY KEY (id);


--
-- Name: finance finance_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT finance_pkey PRIMARY KEY (id);


--
-- Name: users login; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT login UNIQUE (login) INCLUDE (login);


--
-- Name: users phone; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT phone UNIQUE (phone) INCLUDE (phone);


--
-- Name: project project_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.project
    ADD CONSTRAINT project_pkey PRIMARY KEY (id);


--
-- Name: tasks tasks_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_pkey PRIMARY KEY (id);


--
-- Name: transfers transfers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.transfers
    ADD CONSTRAINT transfers_pkey PRIMARY KEY (id);


--
-- Name: finance account; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT account FOREIGN KEY (account) REFERENCES public.accounts(id) NOT VALID;


--
-- Name: finance category; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT category FOREIGN KEY (category) REFERENCES public.categories(id) NOT VALID;


--
-- Name: finance connection; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT connection FOREIGN KEY (communication) REFERENCES public.project(id) NOT VALID;


--
-- Name: accounts counterpar_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accounts
    ADD CONSTRAINT counterpar_id FOREIGN KEY (company_id) REFERENCES public.companies(id) NOT VALID;


--
-- Name: executorsProjects executor; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT executor FOREIGN KEY (executor) REFERENCES public.contacts(id);


--
-- Name: tasks fk_creator; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_creator FOREIGN KEY ("creatorTask") REFERENCES public.users(id) NOT VALID;


--
-- Name: deals fk_customer; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.deals
    ADD CONSTRAINT fk_customer FOREIGN KEY (customer) REFERENCES public.contacts(id) NOT VALID;


--
-- Name: tasks fk_executor; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_executor FOREIGN KEY ("executorTask") REFERENCES public.users(id) NOT VALID;


--
-- Name: project fk_manager; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.project
    ADD CONSTRAINT fk_manager FOREIGN KEY (manager) REFERENCES public.users(id) NOT VALID;


--
-- Name: tasks fk_project; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT fk_project FOREIGN KEY (project) REFERENCES public.project(id) NOT VALID;


--
-- Name: deals fk_responsible; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.deals
    ADD CONSTRAINT fk_responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;


--
-- Name: transfers fk_responsible; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.transfers
    ADD CONSTRAINT fk_responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;


--
-- Name: finance payer; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT payer FOREIGN KEY (payer) REFERENCES public.contacts(id) NOT VALID;


--
-- Name: executorsProjects project; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."executorsProjects"
    ADD CONSTRAINT project FOREIGN KEY (project) REFERENCES public.project(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- Name: finance responsible; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT responsible FOREIGN KEY (responsible) REFERENCES public.users(id) NOT VALID;


--
-- Name: finance state; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.finance
    ADD CONSTRAINT state FOREIGN KEY (state) REFERENCES public."articleEvent"(id) NOT VALID;


--
-- PostgreSQL database dump complete
--

