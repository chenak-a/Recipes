#include <string>

#include "Category.h"
#include "AbsProduct.h"

int Category::m_indent = 0;

Category::Category(std::string name)
	: AbsCatalogComponent(name)
{
}

Category::Category(const Category & mdd)
	: AbsCatalogComponent(mdd.m_name)
{
	// À compléter pour copier tous les éléments du catalogue contenus dans la catégorie
	for (auto it = mdd.cbegin(); it != mdd.cend(); ++it)
		this->addCatalogComponent(*it);
}

Category * Category::clone(void) const
{
	// À compléter pour construire un nouvel objet Category en appelant le constructeur de copie

	return  new Category(*this);; // À remplacer
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent & member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de produits. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	
	this->m_products.push_back(CatalogComponentPtr(member.clone()));

	return *this->m_products.back(); // À remplacer 
}

CatalogComponentIterator Category::begin()
{
	return m_products.begin();
}

CatalogComponentIterator_const Category::cbegin() const
{
	return m_products.cbegin();
}

CatalogComponentIterator_const Category::cend() const
{
	return m_products.cend();
}

CatalogComponentIterator Category::end()
{
	return m_products.end();
}

void Category::deleteCatalogComponent(CatalogComponentIterator_const child)
{
	// À compléter pour éliminer de la catégorie l'élément auquel réfère l'itérateur
	
	m_products.erase(child);
	delete& child;
}

void Category::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de la catégorie
	for (auto it = m_products.cbegin(); it != m_products.cend(); ++it)
	{
		it->get()->deleteCatalogComponent(it);
	}
	m_products.clear();
}

const AbsProduct* Category::findProduct(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans la catégorie à la recherche d'un produit
	// portant le nom reçu en argument. Si aucun produit n'est trouvé on retourne nullptr
	const AbsProduct* foundProduct = nullptr;

	// À compléter
	for (auto& product : m_products) {
		foundProduct = (product.get()->getName() == productName) ? 
			dynamic_cast<AbsProduct*>(product.get()) : product->findProduct(productName);

		if (foundProduct != nullptr) {
			break;
		}
		
	}
	
	
	return foundProduct;
}

std::ostream & Category::printToStream(std::ostream & o) const
{
	// À compléter pour imprimer sur un stream une catégorie et ses produits
	o << "Category: " << getName() << std::endl ;
	m_indent++;
	for (auto it = m_products.cbegin(); it != m_products.cend(); ++it)
	{
		indent(o);
		o << *it->get();
	
	
	}
	m_indent--;
	o<<std::endl;

	return o;
}

std::ostream & Category::indent(std::ostream & o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
