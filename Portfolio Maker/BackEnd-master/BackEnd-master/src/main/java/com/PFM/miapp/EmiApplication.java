package com.PFM.miapp;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;

@SpringBootApplication(exclude = {SecurityAutoConfiguration.class })
public class EmiApplication {

	public static void main(String[] args) {
		SpringApplication.run(EmiApplication.class, args);
	}

}
