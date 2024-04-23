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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: Customer; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Customer" (
    "ID" character(6) NOT NULL,
    "LastName" character varying(30),
    "FirstName" character varying(30),
    address character varying(30),
    "City" character(2),
    state character(5),
    zip character varying(10),
    phone character varying(30)
);


ALTER TABLE public."Customer" OWNER TO postgres;

--
-- Name: Order; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Order" (
    "ID" character(6) NOT NULL,
    "Customer_id" character(6) NOT NULL,
    "Product_id" character(6) NOT NULL,
    "PurchaseDate" date,
    "Quantity" int4multirange,
    "Total" money
);


ALTER TABLE public."Order" OWNER TO postgres;

--
-- Name: Product; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Product" (
    "Product_id" character(6) NOT NULL,
    "Name" character varying(30),
    "Model" character varying(30),
    "Manufacturer" character varying(30),
    "Unitprice" money,
    inventory int4multirange
);


ALTER TABLE public."Product" OWNER TO postgres;

--
-- Data for Name: Customer; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Customer" ("ID", "LastName", "FirstName", address, "City", state, zip, phone) FROM stdin;
123445	\N	\N	\N	\N	\N	\N	\N
123456	\N	\N	\N	\N	\N	\N	\N
\.


--
-- Data for Name: Order; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Order" ("ID", "Customer_id", "Product_id", "PurchaseDate", "Quantity", "Total") FROM stdin;
100000	123456	000002	\N	\N	\N
\.


--
-- Data for Name: Product; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Product" ("Product_id", "Name", "Model", "Manufacturer", "Unitprice", inventory) FROM stdin;
000001	Banh 1	\N	\N	\N	\N
000002	Banh 2	\N	\N	\N	\N
000003	Keo 1	\N	\N	\N	\N
\.


--
-- Name: Customer Customer_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Customer"
    ADD CONSTRAINT "Customer_pkey" PRIMARY KEY ("ID");


--
-- Name: Order Order_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Order"
    ADD CONSTRAINT "Order_pkey" PRIMARY KEY ("ID");


--
-- Name: Product Product_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Product"
    ADD CONSTRAINT "Product_pkey" PRIMARY KEY ("Product_id");


--
-- Name: Order k1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Order"
    ADD CONSTRAINT k1 FOREIGN KEY ("Customer_id") REFERENCES public."Customer"("ID") NOT VALID;


--
-- Name: Order k2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Order"
    ADD CONSTRAINT k2 FOREIGN KEY ("Product_id") REFERENCES public."Product"("Product_id") NOT VALID;


--
-- Name: TABLE "Customer"; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public."Customer" TO salesman;
GRANT SELECT ON TABLE public."Customer" TO acountant;


--
-- Name: TABLE "Order"; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE public."Order" TO salesman;
GRANT SELECT,INSERT,UPDATE ON TABLE public."Order" TO acountant;


--
-- Name: TABLE "Product"; Type: ACL; Schema: public; Owner: postgres
--

GRANT SELECT ON TABLE public."Product" TO salesman;
GRANT SELECT,INSERT,UPDATE ON TABLE public."Product" TO acountant;


--
-- PostgreSQL database dump complete
--

