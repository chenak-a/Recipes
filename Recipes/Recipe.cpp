///////////////////////////////////////////////////////////
//  Recipe.cpp
//  Implementation of the Class Recipe
//  Created on:      19-mars-2022 11:14:24
//  Original author: francois
///////////////////////////////////////////////////////////

#include "Recipe.h"

Recipe::Recipe(std::string title)
    : AbsIngredient(title,0), m_steps("Steps:")
{
}

Recipe::Recipe(const Recipe& mdd)
    : AbsIngredient(mdd), m_steps(mdd.m_steps)
{
	// � compl�ter pour copier tous les ingr�dients contenus dans la recette
	for (auto it = mdd.cbegin(); it != mdd.cend(); ++it)
	{
		addRecipeComponent(*it);
	}
}

Recipe* Recipe::clone() const
{
	// � compl�ter pour construire un nouvel objet Recipe en appelant le constructeur de copie
	return new Recipe(*this); // � remplacer
}

AbsRecipeComponent& Recipe::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsRecipeComponent& member)
{
	const AbsIngredient& ingredient = dynamic_cast<const AbsIngredient&>(member);
	return addIngredient(ingredient);
}

AbsRecipeComponent& Recipe::addIngredient(const AbsIngredient& ingredient)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur des ingr�dients. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	this->m_ingredients.push_back(RecipeComponentPtr(ingredient.clone()));

	return *this->m_ingredients.back(); // � remplacer 
}

AbsRecipeComponent& Recipe::addStep(const AbsStep& step)
{
	// � compl�ter pour d�l�guer aux �tapes la t�che d'ins�rer une copie de l'�tape re�ue en param�tre.
	// On retourne une r�f�rence � l'objet qui vient d'�tre ins�r� dans le conteneur.
	AbsRecipeComponent& stepadded = m_steps.addRecipeComponent(step);
	
	return stepadded; // � remplacer 
}

RecipeComponentIterator Recipe::begin(){

	return m_ingredients.begin();
}


RecipeComponentIterator_const Recipe::cbegin() const
{
	return m_ingredients.cbegin();
}


RecipeComponentIterator_const Recipe::cend() const
{
	return m_ingredients.cend();
}

RecipeComponentIterator Recipe::end()
{
	return m_ingredients.end();
}

RecipeComponentIterator Recipe::begin_step()
{
	return m_steps.begin();
}

RecipeComponentIterator_const Recipe::cbegin_step() const
{
	return m_steps.cbegin();
}

RecipeComponentIterator_const Recipe::cend_step() const
{
	return m_steps.cend();
}

RecipeComponentIterator Recipe::end_step()
{
	return m_steps.end();
}


void Recipe::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	// � compl�ter pour �liminer de l'ingr�dient auquel r�f�re l'it�rateur
	m_ingredients.erase(child);
	delete& child;
	
}

void Recipe::deleteIngredient(RecipeComponentIterator_const ingredient)
{
	// � compl�ter pour �liminer tous les ingr�dients
	
	for (auto it = ingredient->cbegin(); it != ingredient->cend(); ++it)
	{
		deleteRecipeComponent(it);
	}
	
}

void Recipe::deleteStep(RecipeComponentIterator_const step)
{
	// � compl�ter pour d�l�guer aux �tapes la t�che d'effacer l'�tape � laquelle r�f�re l'it�rateur.
	m_steps.deleteRecipeComponent(step);
}

void Recipe::deleteAllComponents()
{
	// � compl�ter pour �liminer tous les ingr�dients et d�l�guer aux �tapes
	// la t�che d'effacer toutes les �tapes.
}

std::ostream& Recipe::printToStream(std::ostream& o) const 
{
	// � compl�ter pour imprimer sur un stream une recette
	o << "Recipe: " << m_description << std::endl;
	indent(o) << "Ingredients:\n";
	m_indent++;
	for (auto&& ingredient : m_ingredients) {
		indent(o) << *ingredient;
	}
	m_indent--;
	indent(o) << m_steps;
	return o << std::endl;
}