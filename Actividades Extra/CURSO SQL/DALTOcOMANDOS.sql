-- CREATE TABLE users(); -- CAMPO-FIELD = COLUMNA, REGISTRO-RECORD= fila
-- CELDA = VALOR DEL CAMPO- FIELD value
DROP DATABASE IF EXISTS sql_invoicing;
CREATE DATABASE sql_invoicing;
USE sql_invoicing;
SET NAMES utf8;
set character_set_client = utf8mb4;
CREATE TABLE payments_methods (
payment_method_id tinyint(4) NOT NULL auto_increment,
nombre VARCHAR(50) NOT NULL,
primary key (payment_method_id)
) ENGINE=InnoDB auto_increment=5 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
INSERT INTO payments_methods VALUES (1,'Tarjeta de Credito');
INSERT INTO payments_methods VALUES (2, 'Efectivo');
INSERT INTO payments_methods VALUES (3, 'Deposito');
INSERT INTO payments_methods VALUES (4, 'Transferencia Electronica');
CREATE TABLE clients (
	cliente_id int(11) NOT NULL,
    name varchar(50) NOT NULL,
    address varchar(50) NOT NULL,
    ciudad varchar(50) NOT NULL,
    provincia VarCHAR(2) not NUll, -- abreviatura de provincias IATA (https://es.wikipedia.org/wiki/Provincias_de_Argentina)
    telefono varchar(50) default null,
    PRIMARY KEY (cliente_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
INSERT INTO clients VALUES (1, 'Vicente', 'Los Ceibos 300', 'Mendoza', 'MZ', '2634 686999');
INSERT INTO clients VALUES (2, 'Emiliano', 'Los Alerces 600', 'Palmira', 'MZ', '2634 777705');
INSERT INTO clients VALUES (3, 'Yandel', 'Siempre Viva 742', 'Villa Mercedes', 'SL', '0231 345299');
INSERT INTO clients VALUES (4, 'Wisin', 'Las Palmeras 1000', 'CABA', 'BS', '011 776654');
INSERT INTO clients VALUES (5, 'Topitongo', 'Abbey Road 650', 'San Carlos', 'CB', '755 343434');

CREATE TABLE facturas (
	factura_id int(11) NOT NULL,
    numero varchar(50) NOT NULL,
    cliente_id int(11) NOT NULL,
    factura_total decimal(9,2) not null,
    pago_total decimal(9,2) not null default '0.00',
    factura_fecha date not null,
    fecha_vencimiento date not null,
    pago_fecha date default null,
    PRIMARY KEY(factura_id),
	KEY FK_cliente_id (cliente_id),
    CONSTRAINT FK_cliente_id foreign key(cliente_id) REFERENCES clients (cliente_id) 
    ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
INSERT INTO facturas VALUES (1, '91-976-3396', 2, 2100.00, 0.00,'2024-05-09', '2025-05-15', NULL);
INSERT INTO facturas VALUES (2, '32-445-5635', 5, 15000.00, 15000.00, '2024-05-11', '2024-05-15', '2024-05-11');
INSERT INTO facturas VALUES (3, '23-343-1111', 5, 14500.50, 0.00, '2024-04-11', '2024-04-15', null);
INSERT INTO facturas VALUES (4, '22-363-4511', 3, 500.00, 0.00, '2024-04-01', '2024-04-15', null);
INSERT INTO facturas VALUES (5, '87-123-3455', 3, 13555.00, 100.00, '2024-01-09', '2024-06-10', '2024-01-01');
INSERT INTO facturas VALUES (6, '56-123-2332', 2, 9000.00, 1100.00, '2024-01-09', '2024-06-10', '2024-01-01');
INSERT INTO facturas VALUES (7, '45-234-1414', 1, 80000.00, 100.00, '2024-01-09', '2024-06-10', '2024-01-01');
INSERT INTO facturas VALUES (8, '34-987-5654', 4, 5700.00, 0.00, '2024-04-19', '2024-04-19', NULL);
INSERT INTO facturas VALUES (9, '23-567-8562', 4, 67099.00, 0.00, '2024-02-09', '2024-02-10', NULL);
INSERT INTO facturas VALUES (10, '12-464-1235', 3, 13000.00, 0.00, '2024-01-03', '2024-01-15', NULL);
INSERT INTO facturas VALUES (11, '87-525-9089', 2, 14000.00, 0.00, '2024-03-09', '2024-03-15', NULL);
INSERT INTO facturas VALUES (12, '58-232-8676', 1, 1000.00, 0.00, '2024-03-01', '2024-03-15', null);
INSERT INTO facturas VALUES (13, '54-565-4543', 5, 41000.00, 0.00, '2024-04-06', '2024-04-15', null);
INSERT INTO facturas VALUES (14, '67-474-2333', 4, 135.00, 87.00, '2024-01-07', '2024-07-15', '2024-01-11');
INSERT INTO facturas VALUES (15, '87-565-1111', 3, 135.00, 87.00, '2024-04-25', '2024-12-15', '2024-01-14');
INSERT INTO facturas VALUES (16, '23-787-2222', 5, 13222.00, 0.00, '2024-01-09', '2024-06-10', null);
INSERT INTO facturas VALUES (17, '13-080-3333', 2, 135.00, 100.00, '2023-07-30', '2023-08-10', '2024-01-15');
INSERT INTO facturas VALUES (18, '52-009-4444', 1, 135.00, 42.00, '2024-04-23', '2024-06-12', '2024-01-08');
INSERT INTO facturas VALUES (19, '34-000-5555', 1, 67700.00, 100.00, '2023-11-23', '2023-12-13', '2024-01-01');

CREATE TABLE pagos (
	pago_id int(11) NOT NULL AUTO_INCREMENT,
	cliente_id int(11) NOT NULL,
    factura_id int(11) NOT NULL,
	fecha date not null,
	cantidad decimal(9,2) NOT NULL,
	payment_method tinyint(4) NOT NULL,
	PRIMARY KEY(pago_id),
    KEY fk_cliente_id_idx (cliente_id),
    KEY fk_factura_id_idx (factura_id),
    KEY fk_pago_payment_method_idx (payment_method),
    CONSTRAINT fk_pago_cliente FOREIGN KEY (cliente_id) REFERENCES clients (cliente_id) ON UPDATE CASCADE,
    CONSTRAINT fk_pago_factura FOREIGN KEY (factura_id) REFERENCES facturas (factura_id) ON UPDATE CASCADE,
    CONSTRAINT fk_pago_payment_method FOREIGN KEY (payment_method) REFERENCES payments_methods (payment_method_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;
INSERT INTO pagos VALUES (1, 5, 2, '2024-05-11', 15000.00, 3);
INSERT INTO pagos VALUES (2, 3, 5, '2024-01-01',  100.00, 2);
INSERT INTO pagos VALUES (3, 2, 6, '2024-01-01',1100.00, 1);
INSERT INTO pagos VALUES (4, 1, 7, '2024-01-01', 100.00, 1);
INSERT INTO pagos VALUES (5, 4, 14, '2024-01-11', 87.00, 1);
INSERT INTO pagos VALUES (6, 3, 15, '2024-01-14', 87.00, 4);
INSERT INTO pagos VALUES (7,2,17,'2024-01-15',100.00,4);
INSERT INTO pagos VALUES (8,1,18, '2024-01-08', 42.00,2);
INSERT INTO pagos VALUES (9,1,19,'2024-01-01',100.00,1);
;

